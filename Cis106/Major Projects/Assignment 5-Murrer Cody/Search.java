// **********************************************************
// Title: Assignment 5
// File: Search.java
// Author: Cody Murrer
// Description: Major Project five
// **********************************************************
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;
import java.util.Scanner;

public class Search extends JFrame implements ActionListener {
   
   int run,i,k;
   int x = 30;
   int y = 100;
   int w,q,rw,b,rh,s;
   
   JFrame root = new JFrame();

   JPanel search = new JPanel();
   
   JTextField ser = new JTextField();
   
   JButton searchFile = new JButton();
   JButton rtn = new JButton();
   
   JLabel desc = new JLabel();
   JLabel repName = new JLabel();
   JLabel sep = new JLabel();
   
   public static void main(String[] args){
      new Search();
   }
   
   public Search(){
// Creates the starting GUI on search screen  
      search.setLayout(null);
   
      desc.setBounds(70,10,150,90);
      desc.setText("Enter desired recipe name");
      
      ser.setBounds(100,90,90,40);
      
      rtn.setBounds(100, 210, 90,40);
      rtn.setText("Return");
      rtn.addActionListener(this);
      
      searchFile.setText("Search");
      searchFile.setBounds(100,150,90,40);
      searchFile.addActionListener(this);
      
      sep.setOpaque(true);
      sep.setBackground(Color.black);
      sep.setBounds(0,60,500,2);
      sep.setVisible(false);
      
      search.add(sep);
      search.add(searchFile);
      search.add(ser);
      search.add(desc);
      search.add(rtn);
      
      root = new JFrame("Cooking Manual");     
      root.setSize(300, 300);
      root.setResizable(false);
      root.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      root.setLocationRelativeTo(null);
      root.setVisible(true);
      root.add(search);
   }

   public void fReader(){
 
   String look;
   String find;
   String nbr;
   int linecount = 0;
   int indexfound;  

	File file = null;
   FileReader frdr = null;
// opens file to read      
	try {
        frdr = new FileReader("Recipes.txt");
        BufferedReader br=new BufferedReader(frdr);
// takes the input and finds recipe within txt file           
         while ((look=br.readLine())!=null){
			  linecount++;
			  indexfound=look.indexOf(ser.getText().toLowerCase());
						  if (indexfound>-1){
// sets name of recipe to label                      
                       find = look; 
                       q = find.length()*100;
                       repName.setBounds(20,20,q,30);
                       repName.setFont(new Font("Serif", Font.PLAIN, 30));
                       repName.setText(find.toUpperCase());
                       search.add(repName);
// finds number of ingredients and intructions                       
						     look = br.readLine();
                       nbr = look;
                       run = Integer.parseInt(nbr);
// sets the length of both arrays                        
                       JLabel[] sub = new JLabel[run];
                       String[] recipe = new String[run];
                        rw = run *100;
                        b = rh + 400;
// populates JLabel and String array and prints onto screen                     
                     for(i=0; i<run;i++){
                        look = br.readLine();
                        look.toString();
// fills arrays with text wanted                          
                        recipe[i] = new String(look);
                        sub[i] = new JLabel(recipe[i]);
                        search.add(sub[i]);
                        w = look.length() * 10; 
                        rh = look.length()*10;
                        sub[i].setBounds(x,y,w,30);
                        s = rh - 110;
                        y += 60;
                        search.revalidate();                                                    
                     }

                }                        
			  }
               
	} catch (Exception e) {
		e.printStackTrace();
	}finally {
		try {
			if (frdr != null) {
				frdr.close();
			}
		} catch (Exception e2) {
			e2.printStackTrace();
		}         	 
     }   
   }

   
   public void actionPerformed(ActionEvent e) { 
// sets conditions for the button presses       
      if(e.getSource()==searchFile){
         if(ser.getText().equals("")){
            JOptionPane.showMessageDialog(null,"Please enter a recipe before proceding.","Input Error",JOptionPane.ERROR_MESSAGE);
         }else{            
            fReader();
            root.setSize(rw, rh);
            root.setResizable(false);
            root.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            root.setLocationRelativeTo(null);
            
            rtn.setBounds(s,b,90,40);
            
            sep.setVisible(true);      
            desc.setVisible(false);
            ser.setVisible(false);
            searchFile.setVisible(false);
         }               
      }
      
      if(e.getSource() == rtn){
            new Manual();
            root.dispose();
         }
   }
   
}