// *******************************************************
// * CIS 106 Final Exam - Programming Part
// * NAME:  Cody Murrer.  2 points
// * FILE:  MenuItem.java
// *******************************************************
// Directions:  Replace the ??? through out the code with
//              the appropriate Java code. 2 points each

// 1. Replace the ??? with the appropriate code
public class MenuItem extends Item {
   private String prepirationDate;
   private boolean glutenFree;
   
   public MenuItem(String number, String desc, double pr, boolean tx, int qty, String prep, boolean gf, String imfn) {
      // 2. Replace the ??? with the appropriate code
      super(number, desc, pr, tx, qty, imfn);
      setPrepirationDate(prep);
      setGlutenFree(gf);
   }

   public MenuItem() {
      super("", "", 0.0, false, 0, "");
      setPrepirationDate("");
      // 3. Replace the ??? with the appropriate code to call the method to set gluten free to true
      setGlutenFree(true);
   }

   // 4. Replace the ??? with the appropriate code
   public void setPrepirationDate(String prep) {
      prepirationDate = prep;
   }
   
   public void setGlutenFree(boolean gf) {
      glutenFree = gf;
   }

   public String getPrepirationDate() {
      return prepirationDate;
   }
   
   // 5. Replace the ??? with the appropriate code
   public boolean getGlutenFree() {
      return glutenFree;
   }

   public String toString() {
      String retVal = "";
      retVal += super.toString()+"\n";
      retVal += "Prepiration Date: "+getPrepirationDate()+"\n";
      // 6. Replace the ??? with the appropriate code
      retVal += (getGlutenFree()?"GlutenFree":"Non-glutenFree");
      return retVal;
   }

}