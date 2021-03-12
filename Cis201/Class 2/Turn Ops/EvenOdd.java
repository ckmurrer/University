import java.util.Scanner;

public class EvenOdd{
   public static void main(String[] args){
      
      Scanner key = new Scanner(System.in);
      System.out.print("Please enter a number: ");
      
      int number = Integer.parseInt(key.nextLine());
      System.out.println("The number "+number+" is "+oddEven(number)+".");
   }
   public static String oddEven(int num){
      return num%2==0?"even":"odd";   
   }
}