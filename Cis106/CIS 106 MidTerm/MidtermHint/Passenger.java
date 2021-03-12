// Midterm Programming Hint - Passenger Class
public class Passenger {
   private String firstName;     // String variable to hold the passenger's first name
   private String lastName;      // String variable to hold the passenger's last name
   private int seatNumber;       // int variable to hold the passenger's seat number
   private double ticketPrice;   // double variable to hold the passenger's ticket price
   private boolean specialNeeds; // boolean variable to note if the passenger has special needs
   private String section;       // String variable to hold the passenger's section (e.g., First Class, Coach)
   
   // Constructors:
   public Passenger(String fn, String ln, int seat, double price, boolean sn) {
      setFirstName(fn);
      setLastName(ln);
      setSeatNumber(seat); 
      setTicketPrice(price);
      setSpecialNeeds(sn);
   }
   
   public Passenger() {
      this("", "", 0, 0.0, false);
   }
   
   // Mutators:
   public void setFirstName(String f) {
      this.firstName = f;
   }
   
   public void setLastName(String l) {
      this.lastName = l;
   }
     
   public void setSeatNumber(int seatNumber) {
      this.seatNumber = seatNumber;
      setSection();
   }
   
   public void setTicketPrice(double price) {
      this.ticketPrice = price;
   }
   
   public void setSpecialNeeds(boolean specialNeeds) {
      this.specialNeeds = specialNeeds;
   }
   
   // Note the use of a nested if-else structure to set the section from the seat number.
   public void setSection() {
      if (seatNumber <= 20)
         section = "First Class";
      else if (seatNumber < 50)
         section = "Sleeper";
      else
         section = "Coach";
   }

   // Accesssors:
   public String getFirstName() {
      return this.firstName;
   }
   
   public String getLastName() {
      return this.lastName;
   }
   
   public int getSeatNumber() {
      return this.seatNumber;
   }
   
   public double getTicketPrice() {
      return this.ticketPrice;
   }
   
   public String getSection() {
      return this.section;
   }

   public boolean getSpecialNeeds() {
      return this.specialNeeds;
   }

   public String toString() {
      String result = "Passenger:\n";
      result += "Last Name: "+getLastName()+"\n";
      result += "First Name: "+getFirstName()+"\n";
      result += "Seat Number: "+getSeatNumber()+" ("+getSection()+")\n";
      result += (getSpecialNeeds()?"*** Special Needs ***":"Regular Ticket")+"\n";
      result += String.format("Ticket Price: $%3.2f",getTicketPrice()); // Using String.format to give 2 digits afer the decimal
      return result;
   }
}
