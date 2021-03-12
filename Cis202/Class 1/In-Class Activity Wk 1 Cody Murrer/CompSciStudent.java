// **********************************************************************************
// Title: 
// Author: Your Name
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: CompSciStudent.java
// Description: 
// **********************************************************************************

public class CompSciStudent extends Person {
   private String program;
   private String email;
   private String hardware;
   private String software;
   private String programming;
   private int seatNumber;
   private String interests;

   // Constructors:
   
   // Replacement for default constructor:
   public CompSciStudent() {   
      super();
      this.program="";
      this.email="";
      this.hardware="";
      this.software="";
      this.programming="";
      this.seatNumber=0;
      this.interests="";
   }
   
   // Complete parameters constructor
   public CompSciStudent(String firstName, String middleName, String lastName, String gender,
                    int age, String program, String email, String hardware, String software,
                    String programming, int seatNumber, String interests) {
      super(firstName, middleName, lastName, gender, age);
      this.program=program;
      this.email=email;
      this.hardware=hardware;
      this.software=software;
      this.programming=programming;
      this.seatNumber=seatNumber;
      this.interests=interests;
   }

   // Mutators:
   
   // Add set methods for all attributes
   public void setProgram(String p){
      this.program = p;
   }
   public void setEmail(String eml){
      this.email = eml;
   }
   public void setHardware(String hw){
      this.hardware = hw;
   }
   public void setSoftware(String sw){
      this.software = sw;
   }
   public void setProgramming(String pgm){
      this.programming = pgm;
   }
   public void setSeatNumber(int seat){
      this.seatNumber = seat;
   }
   public void setInterests(String inter){
      this.interests = inter;
   }

   
   // Accessors:

   // Add get methods for all attributes
   
   public String getProgram(){
      return this.program;
   }
   public String getEmail(){
      return this.email;
   }
   public String getHardware(){
      return this.hardware;
   }
   public String getSoftware(){
      return this.software;
   }
   public String getProgramming(){
      return this.programming;
   }
   public int getSeatNumber(){
      return this.seatNumber;
   }
   public String getInterests(){
      return this.interests;
   }  
   
   public String toString() {
      String result = super.toString();
      // concatenate attributes to the result String variable   
      
      result += "Program/Major: "+getProgram()+"\n";
      result += "Email: "+getEmail()+"\n";
      result += "Hardware: "+getHardware()+"\n";
      result += "Software: "+getSoftware()+"\n";
      result += "Programming Language(s): "+getProgramming()+"\n";
      result += "Seat Number: "+String.format("%03d",getSeatNumber())+"\n";
      result += "Interests: "+getInterests()+"\n";
      return result;
   }
}