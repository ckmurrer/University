// **********************************************************
// Title: Chapter 2 Programming Activity using JOptionPane
// File: TestAverage.java
// Author: Cody Murrer
// Description: This program computes the average of three
//              test scores and displays the socres and the
//              average using special formating.
// **********************************************************
import javax.swing.JOptionPane;

public class TestAvg {

   public static void main(String[] args) {
   
      splash();  // Display a splash page;
      String input; // Temporary variable to hold String input from JOptionPane.showInputDialog method.
      
      int test1; // Hold the score for test 1.
      int test2; // Hold the score for test 2.
      int test3; // Hold the score for test 3.
      
      double average; // Holds the average calculated for the three tests.
      
      // Input the first test score
      
      input = JOptionPane.showInputDialog("What is the first test score? ");
      
      // Convert the input String to an int value and store it in the variable test1.
      
      test1 = Integer.parseInt(input);
      
      // ********************************
      // Do the same for test2 and test3
      // ********************************
      
      input = JOptionPane.showInputDialog("What is the second test score? ");
      test2 = Integer.parseInt(input);
      
      input = JOptionPane.showInputDialog("What is the third test score? ");
      test3 = Integer.parseInt(input);

      // ************************************************************************************************
      // Calcualted the average of the three test scores and store the result in the average variable.
      // ************************************************************************************************
      
      average = (double) (test1 + test2 + test3)/3;
      
      // Display the three test scores and the average using String.format
      
      JOptionPane.showMessageDialog(null, "Test Information:\n"+
                                          "*********************\n"+
                                          String.format("Test 1: %3d\n",test1)+
                                          String.format("Test 2: %3d\n",test2)+
                                          String.format("Test 3: %3d\n",test3)+
                                          String.format("Average: %6.2f\n",average));      
                                          
   }
   
   // Introductory splash page
   
   public static void splash() {
   
      JOptionPane.showMessageDialog(null, "Test Average\n"+
                                          "*********************\n"+
                                          "This program will\n"+
                                          "calculate the average\n"+
                                          "of three test scores.",
                                          "Test Average", JOptionPane.PLAIN_MESSAGE);
                                          
   }
}