// **********************************************************
// Title: Service Plan
// File: SerivcePlan.java
// Author: Cody Murrer
// Description: To get the information from the inputs and print
// them out when called upon in a differnt file
// **********************************************************

public class ServicePlan{

// Attributes
   private String customerName;
   private String product;
   private double planPrice;
   private int planYears;
   
// Constructor
   public ServicePlan(String cName, String prod, double price, int years){
   
      customerName = cName;
      product = prod;
      planPrice = price;
      planYears = years;
      
   }
// Mutators

   public void setCustomerName(String name){
      customerName = name;
   }
   
   public void setProduct(String prod){
      product = prod;
   }
   
   public void setPlanPrice(double prc){
      planPrice = prc;
   }
   
   public void setPlanYears(int yrs){
      planYears = yrs;
   }
// accessors

   public String getCustomerName(){
      return customerName;
   }
   
   public String getProduct(){
      return product;
   }
   
   public double getPlanPrice(){
      return planPrice;
   }
   
   public int getPlanYears(){
      return planYears;
   }
   
   public String toString(){
      String result = "";
      result += "Customer Name: "+ getCustomerName()+"\n";
      result += "Product: "+ getProduct()+"\n";
      result += "Plan Price: "+ getPlanPrice()+"\n";
      result += "Number of Years in Plan: "+ getPlanYears()+"\n";

      return result;
   }
}