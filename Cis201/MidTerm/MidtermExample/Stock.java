public class Stock {

   // Attributes:
   private String symbol;
   private String corporation;
   private double closingPrice;
   private int volume;

   private static boolean noCorporation=true;
   
   // Constructors:
   public Stock() {
      symbol = "";
      corporation = "";
      closingPrice = 0.0;
      volume = 0;
   }
   public Stock(String symbol, String corporation, double closing, int vol) {
      this.symbol = symbol;
      this.corporation = corporation;
      this.closingPrice = closing;
      this.volume = vol;
   }
   
   // Mutators:
   public void setSymbol(String symbol) {
      this.symbol = symbol;
   }
   public void setCorporation(String corporation) {
      this.corporation = corporation;
   }
   public void setClosingPrice(double closing) {
      this.closingPrice = closing;
   }
   public void setVolume(int vol) {
      this.volume = vol;
   }
   public static void setNoCorporation(boolean n) {
      noCorporation = n;
   }
   
   // Accessors:
   public String getSymbol() {
      return this.symbol;
   }
   public String getCorporation() {
      return this.corporation;
   }
   public double getClosingPrice() {
      return this.closingPrice;
   }
   public int getVolume() {
      return this.volume;
   }

   public static boolean getNoCorporation() {
      return noCorporation;
   }
   
   
   public String toString() {
      String result = "";
      if (getNoCorporation()) {
         result += getSymbol()+"\n"+getClosingPrice()+"\n"+getVolume();
      }
      else {
         result = "Corporate Name: "+getCorporation()+"\n";
         result += "Symbol: "+getSymbol()+"\n";
         result += "Closing Price: "+getClosingPrice()+"\n";
         result += "Trading Volume: "+getVolume();
      }
      return result;
   }   
}   