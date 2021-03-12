import javax.swing.JOptionPane;

public class PlayWithDialogBoxes{
   public static void main(String[] args){
   
      JOptionPane.showMessageDialog(null, "This is an example program for \n"+
                                    "Demonstrating dialog boxes using\nJOtoptionPane from the swing package.");
                                    
      String name= JOptionPane.showInputDialog(null, "What is your name");
      int age = Integer.parseInt(JOptionPane.showInputDialog(null, name+", what is your age"));
      double height = Double.parseDouble(JOptionPane.showInputDialog(null, name+", what is your height"));
      boolean student = JOptionPane.showConfirmDialog(null, name+", are you a student")==JOptionPane.YES_OPTION;
      
      JOptionPane.showMessageDialog(null, "Name: "+name+"\nAge in two years: "+(age+2)+"\nHeight: "+String.format("%3.1f\n",height)+"student: "+student+".");
   }
}