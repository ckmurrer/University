// **********************************************************
// Title: Names
// File: Names.java
// Author: Cody Murrer
// Description: uses arrays and a switch case that is being controlled by a for loop
// **********************************************************
//https://www.momjunction.com/articles/unique-names-baby-girl_0022910/
import java.util.Scanner;
public class Names{

int x,i;


   public static void main(String[] args){     
      
      new Names(); 
   }
   
   public Names(){
      
      String[] PresetName = new String[6];
      String[] PresetDesc = new String[6];
      
      PresetName[0] = "Astrid";
      PresetDesc[0] = "Astrid means divinely beautiful";
      PresetName[1] = "Celeste";
      PresetDesc[1] = "Celeste means heavenly";
      PresetName[2] = "Nia";
      PresetDesc[2] = "Nia means resolve";
      PresetName[3] = "Tabitha";
      PresetDesc[3] = "Tabitha means gazelle";
      PresetName[4] = "Atticus";
      PresetDesc[4] = "Atticus means from Attica";
      PresetName[5] = "Eugene";
      PresetDesc[5] = "Eugene means well-born";
   
      Scanner input = new Scanner(System.in);
   
      System.out.print("Please enter a name: ");
      
      String NameInput = input.nextLine();
      
      for(int i = 0; i < PresetName.length; i++){
         if(NameInput.equals(PresetName[i])){
            x = i + 1;
            break;
         }else{
            System.out.println("Input A Valid Name Please");        
            break;
         }
      }
      
      switch(x){
         
         case 1:
              System.out.println(PresetName[0]);
              System.out.println(PresetDesc[0]);
         break;
         
         case 2:
              System.out.println(PresetName[1]);
              System.out.println(PresetDesc[1]);
         break;
         
         case 3:
              System.out.println(PresetName[2]);
              System.out.println(PresetDesc[2]);
         break;
         
         case 4:
              System.out.println(PresetName[3]);
              System.out.println(PresetDesc[3]);
         break;
         
         case 5:
              System.out.println(PresetName[4]);
              System.out.println(PresetDesc[4]);
         break;
         
         case 6:
              System.out.println(PresetName[5]);
              System.out.println(PresetDesc[5]);
         break;
         
         case 7:
              System.out.println(PresetName[6]);
              System.out.println(PresetDesc[6]);
         break; 
      }
   }
}