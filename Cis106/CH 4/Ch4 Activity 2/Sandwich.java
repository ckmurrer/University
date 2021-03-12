/*
Project Name: Ch 4 Activity 2
File: Sandwich.java
Name: Cody Murrer
Description: Sets the accessors and mutators to be called upon by another java class
*/

public class Sandwich{
   //Attributes  
   private String sandwichName;
   private String description;
   private double price;
   private int calories;
   private boolean glutenFree;
   
   public Sandwich(String name, String desc, double pr, int cal, boolean gf){
      sandwichName = name;
      description = desc;
      price = pr; 
      calories = cal;
      glutenFree = gf;
      
   }
   
   public void setSandwichName(String name){
      sandwichName = name;
   }
   public void setDescription(String desc){
      description = desc;
   }
   public void setPrice(double pr){
      price = pr;
   }
   public void setCalories(int cal){
      calories = cal;
   }
   public void setGlutenFree(boolean gf){
      glutenFree = gf;
   }
   
   public String getSandwichName(){
      return sandwichName;
   }
   public String getDescription(){
      return description;
   }
   public double getPrice(){
      return price;
   }
   public int getCalories(){
      return calories;
   }
   public boolean getGlutenFree(){
      return glutenFree;
   }
   
   public String toString(){
      String result="";
      result+="Sandwhich Name "+getSandwichName()+"\n";
      result+="Description "+getDescription()+"\n";
      result+="Price "+String.format("$%4.2f",getPrice())+"\n";
      result+="Calories "+getCalories()+"\n";
      result+=(getGlutenFree()?"Gluten Free":"Contains Gluten");
      return result;
   }
} // sanwich class