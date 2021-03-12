// *******************************************************
// * CIS 106 Midterm Exam - Programming Part
// * NAME:  Cody Murrer  2 points
// * FILE:  Ticket.java
// * COURSE: CIS 106 - Frank Seidel - Spring 2018
// *******************************************************
// Directions:  Replace the ??? through out the code with
//              the appropriate Java code.  2 points each.

// Replace the ??? with the appropriate code
public class Ticket {
   private String firstName;     // String variable to hold the passenger's first name
   private String lastName;      // String variable to hold the passenger's last name
   private int ticketNumber;     // int variable to hold the passenger's ticket number

   // Replace the ??? on the next line with the appropriate data type code
   private String seat;          // String variable to hold the passenger's seat row letter and column number
   private double price;         // double variable to hold the passenger's ticket price
   
   // Replace the ??? on the next line with the appropriate identifier
   private boolean specialMeal;  // boolean variable to note if the passenger has special meal
   private String section;       // String variable to hold the passenger's section (e.g., First Class, Coach)
   
   // Constructors:
   public Ticket(String f, String l, int t, String s, double p, boolean m) {
      setFirstName(f);
      setLastName(l);
      setTicketNumber(t); 
      setSeat(s);
      setPrice(p);
      setSpecialMeal(m);
   }
   
   public Ticket() {
      this("", "", 0, "", 0.0, false);
   }
   
   // Mutators:
   public void setFirstName(String first) {      // Replace the ??? with the appropriate code
      this.firstName = first;
   }
   
   public void setLastName(String last) {
      this.lastName = last;            // Replace the ??? with the appropriate code
   }
     
   public void setTicketNumber(int ticketNumber) {
      this.ticketNumber = ticketNumber;
   }

   public void setSeat(String seat) {
      this.seat = seat;
      setSection();
   }
   
   public void setPrice(double price) {
      this.price = price;
   }
   
   public void setSpecialMeal(boolean specialMeal) {
      this.specialMeal = specialMeal;
   }
   
   // Note the use of a nested if-else structure to set the section from the seat number.
   public void setSection() {
      if (seat.compareToIgnoreCase("F")<0)
         section = "First Class";
      else if (seat.compareToIgnoreCase("M")<0)        // Replace the ??? with the appropriate code segment
         section = "Business Class";
      else
         section = "Economy Class";
   }

   // Accesssors:
   public String getFirstName() {
      return this.firstName;
   }
   
   public String getLastName() {
      return this.lastName;
   }
   
   public int getTicketNumber() {               // Replace the ??? with the appropriate code segment
      return this.ticketNumber;
   }
   
   public double getPrice() {
      return this.price;
   }

   public String getSeat() {          // Replace the ??? with the appropriate code
      return this.seat;
   }
   
   public String getSection() {
      return this.section;
   }

   public boolean getSpecialMeal() {
      return this.specialMeal;
   }

   public String toString() {
      String returnValue;
      returnValue = "Ticket Number: "+getTicketNumber()+"\n";
      returnValue += "Last Name: "+getLastName()+"\n";
      returnValue += "First Name: "+getFirstName()+"\n";
      returnValue += "Seat: "+getSeat()+" ("+getSection()+")\n";
      returnValue += (getSpecialMeal()?"*** Special Meal ***":"Regular Meal")+"\n";
      returnValue += String.format("Ticket Price: $%3.2f",getPrice()); // Using String.format to give 2 digits afer the decimal
      return returnValue;  // Replace the ??? with the appropriate code segment
   }
}
