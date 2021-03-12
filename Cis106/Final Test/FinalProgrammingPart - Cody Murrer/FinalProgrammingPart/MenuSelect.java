// *******************************************************
// * CIS 106 Final Exam - Programming Part
// * NAME:  Cody Murrer.  2 points
// * FILE:  MenuSelect.java
// *******************************************************
// Directions:  Replace the ??? through out the code with
//              the appropriate Java code. 2 points each

import javax.swing.JOptionPane;
import java.util.Scanner;
import java.util.ArrayList;
import java.io.*;
import java.text.NumberFormat;

public class MenuSelect {
   public static final double TAX_RATE = 0.06;
   public static void main(String[] args) throws IOException {
      // Load ArrayList from Inventory File
      ArrayList<MenuItem> mal = new ArrayList<MenuItem>();
      // 1. Replace the ??? with the appropriate code
      ArrayList<MenuItem> mealsPurchased = new ArrayList<MenuItem>();
      File inFile = new File("oldMenu.txt");
      Scanner in = new Scanner(inFile);
      MenuItem mi = null;
      while (in.hasNext()) {
         mi = new MenuItem();
         mi.setNumber(in.nextLine());
         mi.setDescription(in.nextLine());
         mi.setPrice(Double.parseDouble(in.nextLine()));
         mi.setTaxable(in.nextLine().charAt(0)=='t');
         mi.setQuantity(Integer.parseInt(in.nextLine()));
         mi.setPrepirationDate(in.nextLine());
         mi.setGlutenFree(in.nextLine().charAt(0)=='t');
         // 2. Replace the ??? with the appropriate code
         mi.setImageFile(in.nextLine());
         mal.add(mi);
      }
      in.close();
      
      String[] fiNumbernDesc = new String[mal.size()];
      for (int i=0; i<mal.size(); i++) {
         fiNumbernDesc[i] = "["+(i+1)+"] "+mal.get(i).getNumber()+": "+ mal.get(i).getDescription();
      }

      boolean invalid;
      String input = ""; 
      int result=0;
      
      String menuChoice; 
      int qtyPurchased;
      int index;
      MenuItem mp;
      // Purchase MenuItems
      do {
         // Select item
         menuChoice = (String) JOptionPane.showInputDialog(null, "Select menu item:", "Menu System",
                                 JOptionPane.PLAIN_MESSAGE, null, fiNumbernDesc, fiNumbernDesc[0]);
         index = Integer.parseInt(menuChoice.substring(1,menuChoice.indexOf("]")))-1;
                  
         qtyPurchased = 0;
         // Input Quantity
         mi = mal.get(index);
         do {
            invalid = false;
            try {
               input = JOptionPane.showInputDialog(null, mi.toString()+"\nHow many would you like to purchase?\n", "Quantity?", JOptionPane.QUESTION_MESSAGE);
               if (input.length() == 0) throw new Exception("Input is blank.");
               qtyPurchased = Integer.parseInt(input);
               if (qtyPurchased < 0) throw new Exception("Cannot purchase a negative quantity.");
               if (qtyPurchased > mi.getQuantity()) throw new Exception("Menu Item Shortage\nCannot purchase more that "+mi.getQuantity()+".");
            }
            // 3. Replace the ??? with the appropriate code
            catch (Exception e) {
               invalid = true;         
               JOptionPane.showMessageDialog(null, e.getMessage()+"\nPlease enter the quantity to purchase.", "ERROR", 
                  JOptionPane.ERROR_MESSAGE);
            }
         } while (invalid);

         
         // Add item to mealsPurchased list
         mp = new MenuItem();
         mp.setNumber(mi.getNumber());
         mp.setDescription(mi.getDescription());
         mp.setPrice(mi.getPrice());
         mp.setTaxable(mi.getTaxable());
         mp.setQuantity(qtyPurchased);
         // 4. Replace the ??? with the appropriate code
         mp.setImageFile(mi.getImageFile());
         mp.setPrepirationDate(mi.getPrepirationDate());
         mp.setGlutenFree(mi.getGlutenFree());
         mealsPurchased.add(mp);
         
         // Subtract Quantity from mal ArrayList
         mi.setQuantity(mi.getQuantity()-qtyPurchased);
         mal.set(index, mi);
         // 5. Replace the ??? with the appropriate code
      } while (JOptionPane.showConfirmDialog(null, "Would you like to select another item?", "Another?", JOptionPane.YES_NO_OPTION) ==
               JOptionPane.YES_OPTION);
      
      // Display Items Purchased and Subtotal, Tax and Total Sale
      double subtotal = 0.0;
      double lineItem = 0.0;
      double tax = 0.0;
      double total;
      String purchasedItem;
      // 6. Replace the ??? with the appropriate code
      NumberFormat fmt = NumberFormat.getCurrencyInstance();
      for (MenuItem p:mealsPurchased) {
         lineItem = p.getPrice() * p.getQuantity();
         // 7. Replace the ??? with the appropriate code
         JOptionPane.showMessageDialog(null, p.toString()+"\nTotal Cost: "+fmt.format(lineItem), p.getDescription(), JOptionPane.PLAIN_MESSAGE,
            p.getImage());
         
         subtotal += lineItem;
         if (p.getTaxable())
            tax += lineItem * TAX_RATE;
      }
      // 8. Replace the ??? with the appropriate code
      total = subtotal+tax;
      JOptionPane.showMessageDialog(null, "Meal Reciept\n==================\nSubtotal: "+
         fmt.format(subtotal)+"\nTaxes: "+fmt.format(tax)+"\nTotal: "+fmt.format(total), "Meal Total",
         JOptionPane.INFORMATION_MESSAGE);   
   
      // Save ArrayList to new Inventory File
      File outFile = new File("newMenu.txt");
      PrintWriter out = new PrintWriter(outFile);
      
      // Write all of the items in the arraylist to the new inventory file.
      for (int i=0; i<mal.size(); i++) {
         out.println(mal.get(i).getNumber());
         out.println(mal.get(i).getDescription());
         out.println(mal.get(i).getPrice());
         out.println(mal.get(i).getTaxable());
         out.println(mal.get(i).getQuantity());
         out.println(mal.get(i).getPrepirationDate());
         out.println(mal.get(i).getGlutenFree());
         out.println(mal.get(i).getImageFile());
      }
      out.close();
   }
}
