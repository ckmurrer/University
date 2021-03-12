public class Patterns{
   public static void main(String[] args){
      patternA();
    patternB();
      patternC();
     // patternD();
   }
   
   public static void patternA(){
      for(int row = 1; row <= 6; row++){
         for(int col = 1; col <= row; col++){
            System.out.print(col+"");
         }
         System.out.println();
      }
   }  
   public static void patternB(){
      for(int row = 6; row <= 6; row++){
         for(int col = 1; col <= row; col++){
            System.out.print(col+"");
         }
         System.out.println();
      }
   }
   public static void patternC(){
      for(int row = 1; row <= 6; row++){
      int col = 6;
      while (col>row){
         System.out.print("");
         col--;
      }
      while(col>=1){
         System.out.print(col+"");
         col--;
      }
      System.out.println();
    }
   }
}