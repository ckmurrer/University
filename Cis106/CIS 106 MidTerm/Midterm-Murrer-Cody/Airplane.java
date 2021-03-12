// *******************************************************
// * CIS 106 Midterm Exam - Programming Part
// * NAME:  Cody Murrer  2 points
// * FILE:  Airplane.java
// * COURSE: CIS 106 - Frank Seidel - Spring 2018
// *******************************************************
// Directions:  Replace the ??? through out the code with
//              the appropriate Java code.  2 points each.

import javax.swing.JOptionPane;
import java.util.Scanner;
import java.io.File;         // Replace the ??? with the appropriate Java class
import java.io.IOException;

public class Airplane {
   public static void main(String[] args) throws IOException {  // Replace both of the ??? with the appropriate code
      // Create a String to read each line from the input file
      String input;

      // Create a String to hold the name of the input file
      String filename="ticket.txt";

      // Create a counter for the number of ticket objects read.
      int count=0;
      
      // Create a Passenger object
      Ticket ticketIn = new Ticket();  // Replace the ??? with the appropriate keyword and constructor

      // Create an object for the input file
      File inFileObject = new File(filename);  // Replace the ??? with the appropriate code
      
      // If the file does not exist, terminate the program and ask user to copy the file to correct folder.
      if (inFileObject.exists()) {   // Replace the ??? with the appropriate code
         // Create a Scanner object for the input file
         Scanner inFile = new Scanner(inFileObject);
         
         while (inFile.hasNext()) {   // Replace the ??? with the appropriate code
            // Read the input file to obtain the first name
            input = inFile.nextLine();
            
            // Set the first name in the ticket object
            ticketIn.setFirstName(input);
   
            // Read the input file to obtain the last name
            input = inFile.nextLine();
            
            // Set the last name in the ticket object
            ticketIn.setLastName(input);
         
            // Read the input file to obtain the ticket number
            input = inFile.nextLine();
         
            // Set the integer ticket number in the ticket object
            ticketIn.setTicketNumber(Integer.parseInt(input));   // Replace the ??? with the appropriate code

            // Read the input file to obtain the seat location
            input = inFile.nextLine();
            
            // Set the seat location in the ticket object
            ticketIn.setSeat(input);

         
            // Read the input file to obtain the price
            input = inFile.nextLine();
         
            // Set the price in the ticket object
            ticketIn.setPrice(Double.parseDouble(input));

            // Read the input file to obtain special needs
            input = inFile.nextLine();
         
            // Set the special needs setting in the ticket object
            ticketIn.setSpecialMeal(input.toUpperCase().charAt(0)=='T');  // Replace the ??? with the appropriate code
         
            // Output the ticket object  // Replace the ??? on the next line with the appropriate code
            JOptionPane.showMessageDialog(null, ticketIn, "Ticket - Processing #"+ ++count, JOptionPane.INFORMATION_MESSAGE);
         }
      }
      else
         JOptionPane.showMessageDialog(null, "*** ERROR ***\nFile "+filename+" does not exist.\n"+
                        "Please copy the file to the correct folder!", "ERROR", JOptionPane.ERROR_MESSAGE);
   }
}
