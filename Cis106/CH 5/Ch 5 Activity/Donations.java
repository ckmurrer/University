//********************************************
// Project: Ch 5 Actvitiy
// File: Donations.java
// Name: Cody Murrer
// Description: prints out the total and average amounts donated
//********************************************
import javax.swing.JOptionPane;

public class Donations{

   public static void main(String[] args){
      
      double donation = 0.0;
      double total = 0.0;
      double average = 0.0;
      int count = 0;
      
      do {
         donation = Double.parseDouble(JOptionPane.showInputDialog("What is the amount of the donation?"));
         total = total + donation;
         count++;
         
      } while (JOptionPane.showConfirmDialog(null, "Do you wish to enter a new donation?")
               == JOptionPane.YES_OPTION);
               average = total/count;      
      
      JOptionPane.showMessageDialog(null, String.format("The total of the donations was $%4.2f and\n"+
                                                        "the average of the donations was $%4.2f.", total, average));
         
   }// main
}// class