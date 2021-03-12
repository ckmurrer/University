import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;
import java.util.Scanner;

public class Manual extends JFrame implements ActionListener{
   
   JFrame root = new JFrame(); 

   JPanel home = new JPanel();

   JButton htg = new JButton();
   JButton ext = new JButton();
   JButton ent = new JButton();
   JButton src = new JButton();
 
   JLabel head = new JLabel("Welcome to the Cooking Manual");
  
   public static void main(String[] args){
      new Manual();
   }
   
   public Manual(){
         
      home.setLayout(null);
            
   // sets bounds, text, and listeners for components on home screen   
      head.setBounds(63,10,350,40);
      head.setFont(new Font("Serif", Font.PLAIN, 20));
     
      ent.setBounds(142,55,95,40);
      ent.setText("New Entry");
      ent.addActionListener(this);
      
      src.setBounds(142, 105,95,40);
      src.setText("Search");
      src.addActionListener(this);
      
      htg.setBounds(142,155,95,40);
      htg.setText("How To");
      htg.addActionListener(this);
      
      ext.setBounds(142,205,95,40);
      ext.setText("Exit");
      ext.addActionListener(this);
      
   // adds components to the parent frame 
      home.add(head);
      home.add(src);
      home.add(ent);
      home.add(htg);
      home.add(ext);  
               
   // creates the frame and adds home
      root = new JFrame("Cooking Manual");     
      root.setSize(400, 300);
      root.setResizable(false);
      root.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      root.setLocationRelativeTo(null);
      root.setVisible(true);
      root.add(home); 
   }
   
   @Override
   public void actionPerformed(ActionEvent e) { 
   // sets conditions for the button presses            
      if(e.getSource()==ent){
         new Entry();
         root.dispose();
      }   
       
      if(e.getSource()==ext){
         System.exit(0);
      }  
           
      if(e.getSource()==src){
         new Search();
         root.dispose();
      }  
          
      if(e.getSource()==htg){
         new HowTo();
         root.dispose();
      }
   }  
}