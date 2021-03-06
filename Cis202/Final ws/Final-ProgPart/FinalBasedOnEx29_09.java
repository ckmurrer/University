public class FinalBasedOnEx29_09 {
  public static void main(String[] args) throws Exception {
    java.util.Scanner input = new java.util.Scanner(System.in);
    System.out.print("Enter a file name: ");
    java.io.File file = new java.io.File(input.nextLine()) ;  // Replace the ??? with the appropriate constructor for the file object using the input read above.
   
    if (!file.exists()) {
      System.out.println("File does not exist");
      System.exit(1);
    }
    
    java.util.Scanner inFile = new java.util.Scanner(file);
    
    // Read the number of vertices
    String s = inFile.nextLine();
    int numberOfVertices = Integer.parseInt(s);
    System.out.println("The number of vertices is " + numberOfVertices);
    
    java.util.List<WeightedEdge> list = new java.util.ArrayList<WeightedEdge>(); // Replace the ??? with the appropriate List structure.
    
    while (inFile.hasNext()) {
      s = inFile.nextLine();
      
      String[] triplets = s.split("[\\|]");  // This requirement to create the triplets is described in the exercise
      
      for (String triplet: triplets) {
        String[] tokens = triplet.split("[,]");   // Split on the comma
        int u = Integer.parseInt(tokens[0].trim());
        int v = Integer.parseInt(tokens[1].trim());
        int w = Integer.parseInt(tokens[2].trim());
        
        list.add(new WeightedEdge( u, v , w));  // Add the appropriate parameters for the Weighted Edge in one direction
        list.add(new WeightedEdge(v, u, w));  // Add the appropriate parameters for the Weighted Edge in the opposite direction
      }
    }
    
    WeightedGraph<Integer> graph = new WeightedGraph<Integer>(list, numberOfVertices);
    
    graph.printWeightedEdges(); // Print the WeightedEdges for the graph
    WeightedGraph<Integer>.MST tree = graph.getMinimumSpanningTree();  // Get Minimum Spanning Tree for the graph
    System.out.println("Total weight in MST is " + tree.getTotalWeight());
    tree.printTree();  // Print the resulting minimum spanning tree.
  }
}
