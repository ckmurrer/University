// **********************************************************************************
// Title: in class activity one
// Author: Cody Murrer
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: InClassActWk1.java
// Description: 
// **********************************************************************************

public class InClassActWk1{

  private static Person[] student = new CompSciStudent[2];
  
  public static void main(String[] args){
   student[0] = new CompSciStudent("Cody","Konrad","Murrer","Male",19,"CompSci","cmurrer368@myfcc.frederick.edu","PC","Office","Java/HTML/SQL/PHP",4,"Reading/Coding/Gaming/Grilling");
   student[1] = new CompSciStudent("Devin","Taylor","Schmit","Male",20,"CompSci","w1261052@myfcc.frederick.edu","PC","Office","Java/HTML",5,"Drawing/Gaming/Reading");
   
   for(Person p: student)
      System.out.println(p);
  }
}