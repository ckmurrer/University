// ********************************************************************
// Title: Chapter two in class activity
// File: Political.java
// Author: Cody Murrer
// Description: Calculates the percentages of each pary within a survey
// ********************************************************************

import java.util.Scanner;

public class Political{

   public static void main(String[] args){
      Scanner key = new Scanner(System.in);
      int democrats;
      int republicans;
      int independants;
      int total;
   
      double percentDems;
      double percentReps;
      double percentInds;
      
      String input;
      
      System.out.print("Please enter the number of Democrats in the survey: ");
      input = key.nextLine();
      democrats = Integer.parseInt(input);
      
      System.out.print("Please enter the number of Republicans in the survey: ");
      input = key.nextLine();
      republicans = Integer.parseInt(input);
      
      System.out.print("Please enter the number of Independants in the survey: ");
      input = key.nextLine();
      independants = Integer.parseInt(input);
      
      total = democrats + republicans + independants;
      
      percentDems = (double) democrats / total;
      percentReps = (double) republicans / total; 
      percentInds = (double) independants / total;
      
      System.out.printf("The percentage of Democrats in the survey is %5.3f%%. \n", percentDems*100);
      System.out.printf("The percentage of Republicans in the survey is %5.3f%%. \n", percentReps*100);
      System.out.printf("The percentage of Democrats in the survey is %5.3f%%. \n", percentInds*100);

   } //main
} //class