// **********************************************************************************
// Title: Ch 4 in class
// Author: Cdy Murrer
// Course Section: CIS201-HYB2 (Seidel) Fall 2018
// File: Ch4InClass.java
// Description: using descriptive opperators
// **********************************************************************************
import java.util.Scanner;

public class Ch4InClass{
   public static void main(String[] args){
   
      Scanner key = new Scanner(System.in);
      System.out.print("Please enter the first string: ");
      String str1 = key.nextLine();
      System.out.print("Please enter a second string: ");
      String str2 = key.nextLine();
      System.out.println(str1.compareTo(str2));
      System.out.println(str1.compareToIgnoreCase(str2));
      
      if(str1.equalsIgnoreCase(str2)){
         System.out.println(str1.equalsIgnoreCase(str2));
      }else{
         System.out.println("false");
      }
   }
}