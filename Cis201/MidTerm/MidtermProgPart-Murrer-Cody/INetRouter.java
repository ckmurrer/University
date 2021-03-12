// **************************************************************************************************
// Midterm Programming Part - CIS201
// Name:   Cody Murrer                              2 Points
// Description:  This code will allow you to modify the bandwith availability for an internet router 
//               each day of the week.
// Total Points: 24
// **************************************************************************************************

public class INetRouter {                       // Create the class that matched the file name                4 points
   private String location;     //  Type the correct visibility modifiers on these two lines  2 points
   private int bandwidth;
   
   // Constructors:
   public INetRouter(String loc, int band) {                    // Create the appropriate constructor declaration             4 points
      setLocation(loc);
      setBandwidth(band);
   }
   
   public INetRouter() {
      new INetRouter();                  // Call the other constructor with a null string and 0 bandwidth  4 points
   }
   
   // Mutators:
   public void setLocation(String location) {  // Replace the ??? with the appropriate code       1 point
      this.location = location;
   }
   
   public void setBandwidth(int bnd) {    // Replace the ??? with the appropriate code       1 point
      this.bandwidth = bnd;
   }
   
   // Accessors:
   public String getLocation() {      // Replace the ??? with the appropriate code       1 point
      return this.location;
   }
   
   public int getBandwidth() { 
      return this.bandwidth;             // Replace the ??? with the appropriate code       1 point
   }
   
   public String getAvail() {
      String result;
      if (this.bandwidth > 7000)
         result = "High";
      else if (this.bandwidth > 3500)   // Replace the ??? with the appropriate code       2 points
         result = "Medium";
      else 
         result = "Low";
      return result;                           // Replace the ??? with the appropriate code       2 points;
   }
   
   public String toString() {
      String result = "Router: "+getLocation()+"\n";  // Replace the ??? with the appropriate code  1 point
      result += "Bandwidth: "+getBandwidth()+" TBs\n";
      result += "Availability: "+getAvail();       // Replace the ??? with the appropriate code  1 point
      return result;
   }  
}
