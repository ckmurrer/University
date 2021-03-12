// **********************************************************
// Title: Assignment 2 
// File: Assignment2.java
// Author: Cody Murrer
// Description: Major Project two
// **********************************************************
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;



public class Assignment2 extends JFrame implements ActionListener{

int iNum,nNum;

JFrame test = new JFrame();
JPanel test2 = new JPanel();

JTextField ing = new JTextField();
JTextField inst = new JTextField();

JButton cont = new JButton("Continue");

   public static void main(String[] args){
      new Assignment2();
   }
   
   public Assignment2(){
 // creates the frame and panel   
      test2.setLayout(null);
      
      ing.setBounds(10,20,90,40);
      
      inst.setBounds(10,60,90,40);
   
      cont.setBounds(10,100,90,40);
      cont.addActionListener(this);
      
      test2.add(ing);
      test2.add(inst);
      test2.add(cont);


      
      test = new JFrame();     
      test.setSize(200, 200);
      test.setResizable(false);
      test.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      test.setLocationRelativeTo(null);
      test.setVisible(true);
      test.add(test2); 
   }
   
   public void actionPerformed(ActionEvent e) { 
      if(e.getSource()==cont){
         check();
      }
   }
// checks and validates if data is being input and if so then parses the data to integers      
   public void check(){
            if(ing.getText().equals("")|| inst.getText().equals("")){
         JOptionPane.showMessageDialog(null,"Please use an integer in both text fields before proceding.","Input Error",JOptionPane.ERROR_MESSAGE);
      }else{ 
         nNum = Integer.parseInt(inst.getText());
         iNum = Integer.parseInt(ing.getText());
         System.out.println("There are a total of "+(iNum+nNum)+" ingredients and instructions");
     }     
   }     
}