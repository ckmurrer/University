// **********************************************************
// Title: WaterState
// File: WaterState.java
// Author: Cody Murrer
// Description: Tells the user if the temperature of water makes it a gas liquid or solid
// **********************************************************

import java.util.Scanner;

public class WaterState{

   public static void main(String[] args){
      
      Scanner key = new Scanner(System.in);
      double fahrenheightTemp;
      String input;
      String state;
      
      System.out.print("Please enter the temperature of the water in fahrenheight");
      input = key.nextLine();
      fahrenheightTemp = Double.parseDouble(input);
      
      if(fahrenheightTemp <= 32.0){
         state = "solid (ice)";
      }else if(fahrenheightTemp < 212.0){
         state = "liquid (water)";
      }else{
         state = "gaseous (steam)";
      }
      
      System.out.println("The water is in a "+state+" state");
      
   }
}