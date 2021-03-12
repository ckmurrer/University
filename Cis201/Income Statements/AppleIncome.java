//https://finance.yahoo.com/quote/aapl/financials/

public class AppleIncome{
   public static void main(String[] args){
// Revenue     
      int TotRev = 229234000;
      int CosRev = 141048000;
      int GroProf = 88186000;
// Operating Expenses
      int RnD = 11581000;
      int SGnA = 15261000;
      int TOE = 167890000;
      int OIL = 61344000;
// Income for continuing from Operations 
      int TOIEN = 2745000;
      int EBInT = 61344000;
      int IE = -2323000;
      int IBT = 15738000;
      int NICO = 48351000;
// Net Income
      int NeIn = 48351000;
      int NIATCS = 48351000;

// Revenue print      
      System.out.printf("Toal Revenue," +TotRev);
      System.out.printf("Cost of Revenue " +CosRev);
      System.out.printf("Gross Profit, " +GroProf);

// Operating Expenses print      
      System.out.printf("Research and Development " +RnD);
      System.out.printf("Selling General and Administrative " +SGnA);
      System.out.printf("Total Operating Expenses " +TOE);
      System.out.printf("Operating Income or Loss " +OIL);
      
// Income for continuing from Operations print    
      System.out.printf("Total Other Income/Expenses Net " +TOIEN);
      System.out.printf("Earnings Before Interest and Taxes " +EBInT);
      System.out.printf("Interest Expense " +IE);
      System.out.printf("Income Before Tax " +IBT);
      System.out.printf("Net Income From Continuing Ops " +NICO);
      
// Net Income print      
      System.out.printf("Net Income " +NeIn);
      System.out.printf("Net Income Applicable To Common Shares " +NIATCS);
   }
}