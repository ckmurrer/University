// **********************************************************
// Title: Assignment 1 Splash
// File: Assignment1.java
// Author: Cody Murrer
// Description: Gives breif summary of project being proposed
// **********************************************************

import javax.swing.*;

public class Assignment1{
   
    public static void main(String[] args) {
      splash();
   
   }

   public static void splash() {
      JOptionPane.showMessageDialog(null, "The Cooking Manual\n"+
                                          "Cody Murrer\n"+
                                          "CIS106-2\n"+
                                          "********************************************************\n"+
                                          "Stores multiple recipes into a text file that the user inputs\n"+
                                          " then once stored it allows the user to request those recipes anytime they wish.",
                                          "Assignment One", JOptionPane.PLAIN_MESSAGE);
   }
}