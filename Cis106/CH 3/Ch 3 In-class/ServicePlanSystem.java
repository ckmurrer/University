// **********************************************************
// Title: Service Plan System 
// File: SerivcePlanSystem.java
// Author: Cody Murrer
// Description: To show the customer what plan they are on
// **********************************************************
import javax.swing.JOptionPane;

public class ServicePlanSystem{

   public static void main(String[] args){
      
      String name;
      String product;
      double price;
      int years;
      
      name = JOptionPane.showInputDialog("What is the name of the customer?");
      product = JOptionPane.showInputDialog("What product did "+name+" purchase?");
      price = Double.parseDouble(JOptionPane.showInputDialog("What is the price of the service plan?"));
      years = Integer.parseInt(JOptionPane.showInputDialog("How many years does the service plan cover?"));

      ServicePlan serviceP1 = new ServicePlan(name, product, price, years);
      
      JOptionPane.showMessageDialog(null, serviceP1, "Service Plan #1", JOptionPane.PLAIN_MESSAGE);
      
      
   }  //main    
}  // class