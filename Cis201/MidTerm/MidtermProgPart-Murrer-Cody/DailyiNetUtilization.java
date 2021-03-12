// **************************************************************************************************
// Midterm Programming Part - CIS201
// Name:   Cody Murrer                                2 Points
// Description:  This code will allow you to modify the bandwith utilization for an internet router 
//               each day of the week.
// Total Points: 36
// **************************************************************************************************

import java.util.Scanner;                         // Replace the ??? with the appropriate package  2 Points

public class DailyiNetUtilization {                  // Replace the ??? with the appropriate code       2 points
   public static void main(String[] args) {         // Replace the ??? with the appropriate code       2 points
      // Initialize the column heading array as daysOfWeek. // Replace the ??? with the appropriate code 2 points
      String daysOfWeek[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
      // Initialize the row heading array.  // Replace the ??? with the appropriate code       2 points
      String cities[] = {"NY", "DC", "LA"};
      // Initialize the 2D array of daily bandwith utilization.   // Replace the ??? with the appropriate code 2 points
      INetRouter iNetUtil[][] = {{new INetRouter("NY", 0), new INetRouter("NY", 0), new INetRouter("NY", 0), // Replace the ??? with the appropriate code       2 points
                                new INetRouter("NY", 0), new INetRouter("NY", 0)},
                               {new INetRouter("DC",  0), new INetRouter("DC",  0), new INetRouter("DC",  0),
                                new INetRouter("DC",  0), new INetRouter("DC",  0)},
                               {new INetRouter("LA", 0), new INetRouter("LA", 0), new INetRouter("LA", 0),
                                new INetRouter("LA", 0), new INetRouter("LA", 0)}};
      // Declare need variables.
      String input;
      boolean mod = false;
      Scanner key = new Scanner(System.in);  // Replace the ??? with the appropriate constructor code       2 points
      int row;
      int col;
      
      // Display the bandwidth utilization for the week.      
      displayDailyUtil(daysOfWeek, cities, iNetUtil);    // Replace the ??? with the appropriate code 4 points
      
      // Loop while the user wants to make modifications
      do {
         System.out.print("Would you like to modify a router utilization entry? ");
         input = key.nextLine();
         
         // Set mod flag variable
         mod = input.toLowerCase().charAt(0)=='y';
         // Replace the ??? with the appropriate condition for when mod is true 2 points
         if (mod){
            // Get the row number based on city
            row = getIndex(key, "INetRouter Symbol", cities);   // Replace the ??? with the appropriate code  2 points
            // Get the column number based on day of the week
            col = getIndex(key, "Day of the Week", daysOfWeek);
            // If the row and column are valid, allow user to modify the utilization
            if (row >= 0 && col >= 0) {
               modifyINetRouterUtil(key, row, col, iNetUtil);
               displayDailyUtil(daysOfWeek, cities, iNetUtil);
            }
            else
               System.out.println("You cannot modify the utilization without selecting a valid city and day.");
         }
         else {
            System.out.println("Goodbye!");
         }
      } while (mod);  // Loop while the user wishes to modify the utilization.
   }
   
   
   // Display the 2D array
   public static void displayDailyUtil(String[] daysOfWeek, String[] cities, INetRouter[][] iNetUtil) {
      String line = "-------";
      System.out.print("       ");
      for (String day:daysOfWeek) {
         System.out.printf(" %-9s ", day);
         line += "-----------";
      }
      System.out.println("\n"+line);
      // Replace the ??? with the appropriate loop code to count through the rows 4 points      
      for (int row=0; row<cities.length; row++) {
         System.out.printf("%-5s |", cities[row]);
         for(int col=0; col<daysOfWeek.length; col++) {
            System.out.printf("%9d |", iNetUtil[row][col].getBandwidth());
         }
         System.out.println();
         System.out.printf("      |");
         for(int col=0; col<daysOfWeek.length; col++) {
            System.out.printf("%-9s |", iNetUtil[row][col].getAvail());
         }
         System.out.println();

      }
   }
   
   // Get the index of the heading array to match item entered.
   public static int getIndex(Scanner key, String prompt, String[] array) {
      int i=-1;
      boolean invalid;
      String input;
      do {
         try {
            System.out.print("What is the "+prompt+" you are searching for? ");
            input = key.nextLine();
            if (input.length() <= 0) throw new Exception("Please enter the "+prompt+"!");
            i = 0;
            invalid = true;
            while (invalid && i < array.length) {
               if (array[i].equalsIgnoreCase(input)) {
                  invalid = false;
               }
               else {
                  i++; // Replace the ??? with the appropriate code to increment the counting variable       2 points
               }
            }
            if (invalid) throw new Exception(input+"not found!\nPlease enter the "+prompt+"!");
         }
         catch (Exception e) {
            System.out.println("ERROR!\n"+e.getMessage());
            invalid = true;
         }
      } while (invalid);
      return i;
   }

   // Modify the bandwidth utilization at location row,col
   public static void modifyINetRouterUtil(Scanner key, int row, int col, INetRouter[][] iNetUtil) {
      int util=0;
      boolean invalid;
      do {
         try {
            System.out.print("What is the bandwidth utilization? ");
            util = Integer.parseInt(key.nextLine());
            if (util <= 0.0) throw new Exception("Utilization must be positive!");
            invalid = false;
         }
         catch (Exception e) {
            System.out.println("ERROR!\n"+e.getMessage());
            invalid = true;
         }
      } while (invalid);
      // Replace the ??? with the appropriate code       4 points
      iNetUtil[row][col].setBandwidth(util);
   }
}
