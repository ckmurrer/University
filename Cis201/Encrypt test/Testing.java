//http://www.asciitable.com/
import java.util.Scanner;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Testing{


int conAscii;
int leng;
int plswork;
String binpls;
String hexpls;
String plsplspls;
// String[][] 
// String[] 

   public static void main(String[] args){
     new Testing();   
   }
   
   public Testing(){
// gets user input   
      Scanner key = new Scanner(System.in);
      
      System.out.print("Enter the data you wish to be encrypted: ");
      
      plsplspls = key.nextLine();
      leng = plsplspls.length();
      
      Translate();
      
      System.out.println("Do you wish to Decrypt y/n");
   }
   
   public void Translate(){
// converts strings to ascii int value   
      for(int i=0; i < leng; i++){
         conAscii = plsplspls.charAt(i);
         System.out.print(conAscii+".");
      }
      System.out.println("");
      
      for(int j=0; j<leng;j++){
          conAscii = plsplspls.charAt(j);
          hexpls = Integer.toHexString(conAscii);
          System.out.print(hexpls+".");
      }
      System.out.println("");
      
      for(int k=0; k<leng; k++){
          conAscii = plsplspls.charAt(k);
          binpls = Integer.toBinaryString(conAscii);
          System.out.print(binpls+".");
      }
      System.out.println("");
   }

// converts ascii int to hex

// shuffles data

// converts shuffled hex to binary
   
}