import java.util.Scanner;
import 

public class PlayWithStringArray{
   public static void main(String[] args){
      String s;
      Scanner key = new Scanner(System.in);
      System.out.println("Please enter a string ");
      s = key.nextLine();
      
      for(char c:s.toCharArray()){
        System.out.println(c);
      }
   }
}