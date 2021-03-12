import java.util.Scanner;

public class Compare2Strings{
   public static void main(String[] args){
   
      Scanner key = new Scanner(System.in);
      System.out.print("Please enter the first string: ");
      String str1 = key.nextLine();
      System.out.print("Please enter a second string: ");
      String str2 = key.nextLine();
      System.out.println(str1.compareTo(str2));
      System.out.println(str1.compareToIgnoreCase(str2));
   
   }
}