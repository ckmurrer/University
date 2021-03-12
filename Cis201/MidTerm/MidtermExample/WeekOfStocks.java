// This is the sample program for the Midterm Exam.
// It is based on the Stock example and the tic-tac-toe problem that we discussed in class.
// You may use this to help you during the midterm programming part.

import java.util.Scanner;

public class WeekOfStocks {
   public static void main(String[] args) {
      // Initialize the column heading array.
      String daysOfWeek[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
      // Initialize the row heading array.
      String stockSymbols[] = {"ORCL", "ABC", "MCD"};
      // Initialize the 2D array of stock trades.
      Stock stockTrades[][] = {{new Stock("ORCL", "Oracle, Inc", 0.0, 0), new Stock("ORCL", "Oracle, Inc", 0.0, 0), new Stock("ORCL", "Oracle, Inc", 0.0, 0),
                                new Stock("ORCL", "Oracle, Inc", 0.0, 0), new Stock("ORCL", "Oracle, Inc", 0.0, 0)},
                               {new Stock("ABC", "Alphabet, Inc", 0.0, 0), new Stock("ABC", "Alphabet, Inc", 0.0, 0), new Stock("ABC", "Alphabet, Inc", 0.0, 0),
                                new Stock("ABC", "Alphabet, Inc", 0.0, 0), new Stock("ABC", "Alphabet, Inc", 0.0, 0)},
                               {new Stock("MCD", "McDonalds, Inc", 0.0, 0), new Stock("MCD", "McDonalds, Inc", 0.0, 0), new Stock("MCD", "McDonalds, Inc", 0.0, 0),
                                new Stock("MCD", "McDonalds, Inc", 0.0, 0), new Stock("MCD", "McDonalds, Inc", 0.0, 0)}};
      // Declare need variables.
      String input;
      boolean mod = false;
      Scanner key = new Scanner(System.in);
      int row;
      int col;
      
      // Display the closing prices and volume and stock trades for the week.      
      displayWeeklyTrades(daysOfWeek, stockSymbols, stockTrades);
      
      // Loop while the user wants to make modifications
      do {
         System.out.print("Would you like to modify a stock entry? ");
         input = key.nextLine();
         
         // Set mod flag variable
         mod = input.toLowerCase().charAt(0)=='y';
         if (mod) {
            // Get the row number based on stock symbol
            row = getIndex(key, "Stock Symbol", stockSymbols);
            // Get the column number based on day of the week
            col = getIndex(key, "Day of the Week", daysOfWeek);
            // If the row and column are valid, allow user to modify the closing price and volume
            if (row >= 0 && col >= 0) {
               modifyStockTrades(key, row, col, stockTrades);
               displayWeeklyTrades(daysOfWeek, stockSymbols, stockTrades);
            }
            else
               System.out.println("You cannot modify the stock trades without selecting a valid symbol and day.");
         }
         else {
            System.out.println("Goodbye!");
         }
      } while (mod);  // Loop while the user wishes to modify the stock values.
      
      
   }
   
   
   // Display the 2D array
   public static void displayWeeklyTrades(String[] daysOfWeek, String[] stockSymbols, Stock[][] stockTrades) {
      String line = "-------";
      System.out.print("       ");
      for (String day:daysOfWeek) {
         System.out.printf(" %-9s ", day);
         line += "-----------";
      }
      System.out.println("\n"+line);
      
      for (int row=0; row<stockSymbols.length; row++) {
         System.out.printf("%-5s |", stockSymbols[row]);
         for(int col=0; col<daysOfWeek.length; col++) {
            System.out.printf("%9.2f |", stockTrades[row][col].getClosingPrice());
         }
         System.out.println();
         System.out.printf("      |");
         for(int col=0; col<daysOfWeek.length; col++) {
            System.out.printf("%9d |", stockTrades[row][col].getVolume());
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
                  i++;
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

   // Modify the closing price and volume of the stock trade at location row,col
   public static void modifyStockTrades(Scanner key, int row, int col, Stock[][] stockTrades) {
      double close=0.0;
      int vol=0;
      boolean invalid;
      do {
         try {
            System.out.print("What is the closing price? ");
            close = Double.parseDouble(key.nextLine());
            if (close <= 0.0) throw new Exception("Price must be positive!");
            invalid = false;
         }
         catch (Exception e) {
            System.out.println("ERROR!\n"+e.getMessage());
            invalid = true;
         }
      } while (invalid);
      do {
         try {
            System.out.print("What is the trading volume? ");
            vol = Integer.parseInt(key.nextLine());
            if (vol < 0) throw new Exception("Volume e must be positive!");
            invalid = false;
         }
         catch (Exception e) {
            System.out.println("ERROR!\n"+e.getMessage());
            invalid = true;
         }
      } while (invalid);
      stockTrades[row][col].setClosingPrice(close);
      stockTrades[row][col].setVolume(vol);
   }
}
