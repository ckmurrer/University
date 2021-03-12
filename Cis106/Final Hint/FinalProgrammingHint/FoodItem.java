public class FoodItem extends Product {
   private String expirationDate;
   private boolean frozen;
   
   public FoodItem(String upc, String desc, double pr, boolean tx, int qty, String exp, boolean frz, String imfn) {
      super(upc, desc, pr, tx, qty, imfn);
      setExpirationDate(exp);
      setFrozen(frz);
   }

   public FoodItem() {
      super("", "", 0.0, false, 0, "");
      setExpirationDate("");
      setFrozen(true);
   }

   public void setExpirationDate(String exp) {
      expirationDate = exp;
   }
   
   public void setFrozen(boolean frz) {
      frozen = frz;
   }

   public String getExpirationDate() {
      return expirationDate;
   }
   
   public boolean getFrozen() {
      return frozen;
   }

   public String toString() {
      String result = "";
      result += super.toString()+"\n";
      result += "Expiration Date: "+getExpirationDate()+"\n";
      result += (getFrozen()?"Frozen":"Non-frozen");
      return result;
   }

}