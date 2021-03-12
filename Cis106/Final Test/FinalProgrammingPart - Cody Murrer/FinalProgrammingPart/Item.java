// *******************************************************
// * CIS 106 Final Exam - Programming Part
// * NAME:  Cody Murrer.  2 points
// * FILE:  Item.java
// *******************************************************
// Directions:  Replace the ??? through out the code with
//              the appropriate Java code. 2 points each

import javax.swing.ImageIcon;
// 1. Replace the ??? with the appropriate code
import java.text.NumberFormat;

public class Item {
   private String number;
   private String description;
   private double price;
   private boolean taxable;
   private int quantity;
   private String imageFile;
   private ImageIcon image;
   
   // Constructors:
   public Item() {
      setNumber("");
      setDescription("");
      setPrice(0.0);
      setTaxable(false);
      setQuantity(0);
      setImageFile("");
   }
   
   // 2. Replace the ??? with the appropriate code
   public Item(String number, String desc, double pr, boolean tx, int q, String imfn) {
      setNumber(number);
      setDescription(desc);
      setPrice(pr);
      setTaxable(tx);
      setQuantity(q);
      setImageFile(imfn);
   }
   
   // Mutators:
   public void setNumber(String number) {
      this.number = number;
   }
   
   public void setDescription(String desc) {
      this.description = desc;
   }
   
   // 3. Replace the ??? with the appropriate code
   public void setPrice(double pr) {
      this.price = pr;
   }
   
   public void setTaxable(boolean tax) {
      this.taxable = tax;
   }
   
   public void setQuantity(int quant) {
      this.quantity = quant;
   }
   
   public void setImageFile(String imfn) {
      this.imageFile = imfn;
      // 4. Replace the ??? with the appropriate code
      this.image = new ImageIcon(this.imageFile);
   }

   // Accessors:
   public String getNumber() {
      return this.number;
   }
   
   public String getDescription() {
      return this.description;
   }
   
   public double getPrice() {
      return this.price;
   }
   
   public boolean getTaxable() {
      return this.taxable;
   }

   public int getQuantity() {
      return this.quantity;
   }
   
   public String getImageFile() {
      return this.imageFile;
   }
   
   public ImageIcon getImage() {
      return this.image;
   }
   
   public String toString() {
      NumberFormat fmt = NumberFormat.getCurrencyInstance();
      // 5. Replace the ??? with the appropriate code
      String retVal = "";
      retVal += "Item Number: "+getNumber()+"\n";
      retVal += "Description: "+getDescription()+"\n";
      retVal += "Price: "+fmt.format(getPrice())+"\n";
      retVal += (getTaxable()?"Taxable":"Non-taxable")+"\n";
      retVal += "Quantity: "+getQuantity();
      // 6. Replace the ??? with the appropriate code
      return retVal;
   }
}
