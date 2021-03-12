// Midterm Hint - Train.java
// Frank Seidel - CIS106 - Fall 2016
import javax.swing.JOptionPane;
import java.util.Scanner;
import java.io.File;
import java.io.IOException;

public class Train {
   public static void main(String[] args) throws IOException {
      // Create a String to read each line from the input file
      String input;

      // Create a String to hold the name of the input file
      String filename="passengers.txt";

      // Create a counter for the number of passenger objects read.
      int count=0;
      
      // Create a Passenger object
      Passenger passengerIn = new Passenger();

      // Create an object for the input file
      File inFileObj = new File(filename);
      
      // If the file does not exist, terminate the program and ask user to copy the file to correct folder.
      if (inFileObj.exists()) {
         // Create a Scanner object for the input file
         Scanner inFile = new Scanner(inFileObj);
         
         while (inFile.hasNext()) {
            // Read the input file to obtain the first name
            input = inFile.nextLine();
            
            // Set the first name in the passenger object
            passengerIn.setFirstName(input);
   
            // Read the input file to obtain the last name
            input = inFile.nextLine();
            
            // Set the last name in the passenger object
            passengerIn.setLastName(input);
         
            // Read the input file to obtain the seat number
            input = inFile.nextLine();
         
            // Set the seat number in the passenger object
            passengerIn.setSeatNumber(Integer.parseInt(input));
         
            // Read the input file to obtain the price
            input = inFile.nextLine();
         
            // Set the price in the passenger object
            passengerIn.setTicketPrice(Double.parseDouble(input));

            // Read the input file to obtain special needs
            input = inFile.nextLine();
         
            // Set the special needs setting in the passenger object
            passengerIn.setSpecialNeeds(input.toUpperCase().charAt(0)=='T');
         
            // Output the passenger object
            JOptionPane.showMessageDialog(null, passengerIn, "Passenger #"+ ++count +" Read", JOptionPane.INFORMATION_MESSAGE);
         }
      }
      else
         JOptionPane.showMessageDialog(null, "*** ERROR ***\nFile "+filename+" does not exist.\n"+
                        "Please copy the file to the correct folder!", "ERROR", JOptionPane.ERROR_MESSAGE);
   }
}
