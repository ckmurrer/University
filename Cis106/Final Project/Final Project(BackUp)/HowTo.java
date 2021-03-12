import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;


public class HowTo extends JFrame implements ActionListener{

   JFrame root = new JFrame();

   JPanel how = new JPanel();
   
   JLabel howHead = new JLabel("How To");
   JLabel howOne = new JLabel("1) For a new recipe hit the new recipe button.");
   JLabel howTwo = new JLabel("2) Then fill out the provided text fields and hit continue.");
   JLabel howThree = new JLabel("3) After hitting continue fill out the array of text fields and hit submit.");
   JLabel howFour = new JLabel("4) After hitting submit the data gets stored into a file called Recipes.txt.");
   JLabel howFive = new JLabel("5) Then hit the return button to search for a recipe.");
   JLabel howSix = new JLabel("6) When searching for a recipe hit the search button.");
   JLabel howSeven = new JLabel("7) Once at the search screen type in the text field the recipe you wish to find and hit submit.");
   JLabel howEight = new JLabel("8) If the recipe name is within the text document it will print out the full recipe.");
   
   JButton rtn = new JButton("Return");
   
   public static void main(String[] args){
      new HowTo();
   }
   
   public HowTo(){
      how.setLayout(null);
      
      howHead.setBounds(250,5,90,30);
      howHead.setFont(new Font("Serif", Font.PLAIN, 20));
      
      howOne.setBounds(10,40,300,30); 
      howTwo.setBounds(10,70,320,30);
      howThree.setBounds(10,100,390,30);
      howFour.setBounds(10,130,400,30);
      howFive.setBounds(10,160,300,30);
      howSix.setBounds(10,190,300,30);  
      howSeven.setBounds(10,220,530,30);
      howEight.setBounds(10,250,450,30);
      
      rtn.setBounds(480,300,90,40);
      rtn.addActionListener(this);
      
      how.add(rtn);
      how.add(howHead);
      how.add(howOne);
      how.add(howTwo);
      how.add(howThree);
      how.add(howFour);
      how.add(howFive);
      how.add(howSix);
      how.add(howSeven);
      how.add(howEight);
      
      root = new JFrame("Cooking Manual");     
      root.setSize(600, 400);
      root.setResizable(false);
      root.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      root.setLocationRelativeTo(null);
      root.setVisible(true);
      root.add(how); 
          
   }
    public void actionPerformed(ActionEvent e) { 
      if(e.getSource()==rtn){
         new Manual();
         root.dispose();
      }
   }
}