// **********************************************************************************
// Title: Ch 6 in class
// Author: Cdy Murrer
// Course Section: CIS201-HYB2 (Seidel) Fall 2018
// File: FutureInvesrment.java
// Description: lets you see the future investment based on initial amount and monthly rate
// **********************************************************************************

// futureinvestvalue = investamount*(1+monthlyinterestrate)^(years*12)
import java.util.Scanner;


public class FutureInvestment{

double investmentAmount, monthlyInterestRate, futureValue;
int years;

   public static void main(String[] args){
     new FutureInvestment();
   }
   
   public FutureInvestment(){
      Scanner ent = new Scanner(System.in);
      System.out.print("The amount invested: ");
      investmentAmount = Double.parseDouble(ent.nextLine());
      System.out.print("Annual interest rate in percentage: ");
      monthlyInterestRate = Double.parseDouble(ent.nextLine());
      
      monthlyInterestRate = monthlyInterestRate/100;
      monthlyInterestRate = monthlyInterestRate/12;
      
    for(int i = 1; i < 31; i++ ){  
      years = i*12;
      futureValue = investmentAmount*Math.pow(1+monthlyInterestRate,years);
      System.out.println("Year(s): "+i+"\t\t\tFuture Value: "+String.format("%3.1f",futureValue));
      }
   }
}