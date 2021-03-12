//***********************************************************************************
// Title: 
// File Name: Month.java
// Name: Cody Murrer
// Description:
//***********************************************************************************
public class Month{
   
   private int monthNumber;
   
   public Month(){
      this.monthNumber = 1;
   }

   public Month(int monthNumber){
      this.monthNumber = monthNumber;  
   }
   
   public Month(String monthName){
      monthName = monthName.substring(0,3).toLowerCase();
      String monthAb = "jabfebmaraprmayjunjulaugsepoctnovdec";
      this.monthNumber = (monthAb.indexOf(monthName)/3)+1;   
   }
   
   public void setMonthNumber(int monthNumber){
      if(monthNumber < 1 || monthNumber > 12){
         monthNumber = 1;
      }else{
         this.monthNumber = monthNumber;
      }
   }
   
   public int getMonthNumber(){
      return monthNumber;
   }
   
   public String getMonthName(){
      String month="";
   
      switch (monthNumber){
      
         case 1:
            month = "January";
            break;
         case 2:
            month = "February";
            break;
         case 3:
            month = "March";
            break;
         case 4:
            month = "April";
            break;
         case 5:
            month = "May";
            break;
         case 6:
            month = "June";
            break;
         case 7:
            month = "July";
            break;
         case 8:
            month = "August";
            break;
         case 9:
            month = "September";
            break; 
         case 10:
            month = "October";
            break; 
         case 11:
            month = "November";
            break; 
         case 12:
            month = "December";
            break;
      }
         return month;     
   }
   public String toString(){
      return getMonthName();
   }
   public boolean equals(Month m){
      return m.getMonthNumber() == this.getMonthNumber();
   }
   public boolean greaterThan(Month m){
      return m.getMonthNumber() < this.getMonthNumber();
   }
   public boolean lessThan(Month m){
      return m.getMonthNumber() > this.getMonthNumber();
   }
}