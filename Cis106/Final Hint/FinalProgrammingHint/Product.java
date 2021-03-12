import javax.swing.ImageIcon;
import java.text.NumberFormat;

public class Product {
   private String upc;
   private String description;
   private double price;
   private boolean taxable;
   private int quantity;
   private String imageFile;
   private ImageIcon image;
   
   // Constructors:
   public Product() {
      setUPC("");
      setDescription("");
      setPrice(0.0);
      setTaxable(false);
      setQuantity(0);
      setImageFile("");
   }
   
   public Product(String upc, String desc, double pr, boolean tx, int q, String imfn) {
      setUPC(upc);
      setDescription(desc);
      setPrice(pr);
      setTaxable(tx);
      setQuantity(q);
      setImageFile(imfn);
   }
   
   // Mutators:
   public void setUPC(String upc) {
      this.upc = upc;
   }
   
   public void setDescription(String desc) {
      this.description = desc;
   }
   
   public void setPrice(double pr) {
      this.price = pr;
   }
   
   public void setTaxable(boolean tx) {
      this.taxable = tx;
   }
   
   public void setQuantity(int qty) {
      this.quantity = qty;
   }
   
   public void setImageFile(String imfn) {
      this.imageFile = imfn;
      this.image = new ImageIcon(this.imageFile);
   }

   // Accessors:
   public String getUPC() {
      return this.upc;
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
      String result = "";
      result += "Universal Product Code: "+getUPC()+"\n";
      result += "Description: "+getDescription()+"\n";
      result += "Price: "+fmt.format(getPrice())+"\n";
      result += (getTaxable()?"Taxable":"Non-taxable")+"\n";
      result += "Quantity: "+getQuantity();
      return result;
   }
}
