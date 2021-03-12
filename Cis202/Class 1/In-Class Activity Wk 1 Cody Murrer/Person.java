// **********************************************************************************
// Title: Person Class for In-Class Activity Week 1
// Author: Frank (Francis M.) Seidel
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: Person.java
// Description: This class file is used as superclass for the CSStudent class.
// **********************************************************************************
public class Person {
   // Attributes:
   private String firstName;
   private String middleName;
   private String lastName;
   private String gender;
   private int age;
   
   // Constructors:
   
   // Replacement for default constructor:
   public Person() {   
      firstName="";
      middleName="";
      lastName="";
      gender="";
      age=0;
   }
   
   // Complete parameters constructor
   public Person(String firstName, String middleName, String lastName, String gender,
                    int age) {
      this.firstName=firstName;
      this.middleName=middleName;
      this.lastName=lastName;
      this.gender=gender;
      this.age=age;
   }

   // Mutators:
   public void setFirstName(String firstName) {
      this.firstName = firstName;
   }
   public void setMiddleName(String middleName) {
      this.middleName = middleName;
   }
   public void setLastName(String lastName) {
      this.lastName = lastName;
   }
   public void setGender(String gender) {
      this.gender = gender;
   }
   public void setAge(int age) {
      this.age = age;
   }

   
   // Accessors:
   public String getFirstName() {
      return this.firstName;
   }
   public String getMiddleName() {
      return this.middleName;
   }
   public String getLastName() {
      return this.lastName;
   }
   public String getGender() {
      return this.gender;
   }
   public int getAge() {
      return this.age;
   }
   
   public String toString() {
      String result = "";
      // concatenate attributes to the result String variable   
      result += "First Name: "+getFirstName()+"\n";
      result += "Middle Name: "+getMiddleName()+"\n";
      result += "Last Name: "+getLastName()+"\n";
      result += "Gender: "+getGender()+"\n";
      result += "Age: "+String.format("%03d",getAge())+"\n";
      return result;
   }
}
