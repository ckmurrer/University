import javax.swing.JOptionPane;
import java.util.Scanner;
import java.util.ArrayList;
import java.io.*;
import java.text.NumberFormat;

public class GroceryShopping {
   public static final double TAX_RATE = 0.06;
   public static void main(String[] args) throws IOException {
      // Load ArrayList from Inventory File
      ArrayList<FoodItem> fal = new ArrayList<FoodItem>();
      ArrayList<FoodItem> purchases = new ArrayList<FoodItem>();
      
      File inFile = new File("oldInv.txt");
      Scanner in = new Scanner(inFile);
      FoodItem fi = null;
      while (in.hasNext()) {
         fi = new FoodItem();
         fi.setUPC(in.nextLine());
         fi.setDescription(in.nextLine());
         fi.setPrice(Double.parseDouble(in.nextLine()));
         fi.setTaxable(in.nextLine().charAt(0)=='t');
         fi.setQuantity(Integer.parseInt(in.nextLine()));
         fi.setExpirationDate(in.nextLine());
         fi.setFrozen(in.nextLine().charAt(0)=='t');
         fi.setImageFile(in.nextLine());
         fal.add(fi);
      }
      in.close();
      
      String[] fiUPCnDesc = new String[fal.size()];
      for (int i=0; i<fal.size(); i++) {
         fiUPCnDesc[i] = "["+(i+1)+"] "+fal.get(i).getUPC()+": "+ fal.get(i).getDescription();
      }

      boolean invalid;
      String input = ""; 
      int result=0;
      
      String menuChoice; 
      int qtyPurchased;
      int index;
      FoodItem fp;
      // Purchase FoodItems
      do {
         // Select item
         menuChoice = (String) JOptionPane.showInputDialog(null, "Select food item:", "Point-Of-Sales System",
                                JOptionPane.PLAIN_MESSAGE, null, fiUPCnDesc, fiUPCnDesc[0]);
         index = Integer.parseInt(menuChoice.substring(1,menuChoice.indexOf("]")))-1;
                  
         qtyPurchased = 0;
         // Input Quantity
         fi = fal.get(index);
         do {
            invalid = false;
            try {
               input = JOptionPane.showInputDialog(null, fi.toString()+"\nHow many would you like to purchase?\n", "Quantity?", JOptionPane.QUESTION_MESSAGE);
               if (input.length() == 0) throw new Exception("Input is blank.");
               qtyPurchased = Integer.parseInt(input);
               if (qtyPurchased < 0) throw new Exception("Cannot purchase a negative quantity.");
               if (qtyPurchased > fi.getQuantity()) throw new Exception("Inventory Shortage\nCannot purchase more that "+fi.getQuantity()+".");
            }
            catch (Exception e) {
               invalid = true;         
               JOptionPane.showMessageDialog(null, e.getMessage()+"\nPlease enter the quantity to purchase.", "ERROR", 
                  JOptionPane.ERROR_MESSAGE);
            }
         } while (invalid);

         
         // Add item to purchases list
         fp = new FoodItem();
         fp.setUPC(fi.getUPC());
         fp.setDescription(fi.getDescription());
         fp.setPrice(fi.getPrice());
         fp.setTaxable(fi.getTaxable());
         fp.setQuantity(qtyPurchased);
         fp.setImageFile(fi.getImageFile());
         purchases.add(fp);
         
         // Subtract Quantity from fal ArrayList
         fi.setQuantity(fi.getQuantity()-qtyPurchased);
         fal.set(index, fi);
      } while (JOptionPane.showConfirmDialog(null, "Would you like to purchase another item?", "Another?", JOptionPane.YES_NO_OPTION) ==
               JOptionPane.YES_OPTION);
      
      // Display Items Purchased and Subtotal, Tax and Total Sale
      double subtotal = 0.0;
      double lineItem = 0.0;
      double tax = 0.0;
      double total;
      String purchasedItem;
      NumberFormat fmt = NumberFormat.getCurrencyInstance();
      for (FoodItem p:purchases) {
         lineItem = p.getPrice() * p.getQuantity();
         JOptionPane.showMessageDialog(null, p.toString()+"\nTotal Cost: "+fmt.format(lineItem), p.getDescription(), JOptionPane.PLAIN_MESSAGE,
            p.getImage());
         
         subtotal += lineItem;
         if (p.getTaxable())
            tax += lineItem * TAX_RATE;
      }
      total = subtotal+tax;
      JOptionPane.showMessageDialog(null, "Subtotal: "+fmt.format(subtotal)+"\nTaxes: "+fmt.format(tax)+"\nTotal: "+fmt.format(total),"Total",
         JOptionPane.INFORMATION_MESSAGE);   
   
      // Save ArrayList to new Inventory File
      File outFile = new File("newInv.txt");
      PrintWriter out = new PrintWriter(outFile);
      
      // Write all of the items in the arraylist to the new inventory file.
      for (int i=0; i<fal.size(); i++) {
         out.println(fal.get(i).getUPC());
         out.println(fal.get(i).getDescription());
         out.println(fal.get(i).getPrice());
         out.println(fal.get(i).getTaxable());
         out.println(fal.get(i).getQuantity());
         out.println(fal.get(i).getExpirationDate());
         out.println(fal.get(i).getFrozen());
         out.println(fal.get(i).getImageFile());
      }
      out.close();
   }
}
