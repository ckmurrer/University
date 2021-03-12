import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;
import java.util.Scanner;

public class Entry extends JFrame implements ActionListener{
// creates swing attributes   
   JFrame root = new JFrame();
   
   JPanel entry = new JPanel();
   
   JTextField ing = new JTextField();
   JTextField inst = new JTextField();
   JTextField recipeName = new JTextField();  
   
   JButton submit = new JButton();
   JButton cont = new JButton();
   JButton rtn = new JButton();

   JLabel ingred = new JLabel("Please enter how many ingredients there are.");
   JLabel instruc = new JLabel("How many steps are in the recipe.");
   JLabel entTitle = new JLabel("New Recipe Entry");
   JLabel ingTitle = new JLabel("Ingredients");
   JLabel insTitle = new JLabel("Instructions");
   JLabel repName = new JLabel("Please enter the recipe name.");   
// sets ints 
   int iNum;
   int nNum;
   int i,k,j,s;
   int c = 210;
   int r = 100;
   int q = 205;
   int w = 10;
   int p = 480;
   int o = 10;
   int l = 100;
   int m = 485;
   
   public static void main(String[] args){
      new Entry();
   }

   public Entry(){
// Sets layout for panel  
      entry.setLayout(null);
// Sets bounds and text for the components   
      ing.setBounds(313,115,100,30);
      inst.setBounds(247,165,100,30);
      recipeName.setBounds(225,65,100,30);
      
      cont.setText("Continue");
      cont.addActionListener(this);
      cont.setBounds(550,220,90,30);
      
      rtn.setText("Return");
      rtn.addActionListener(this);
      rtn.setBounds(660,220,90,30);
      
      submit.setText("Submit");
      submit.setBounds(600,700,90,30);
      
      entTitle.setFont(new Font(null, Font.PLAIN, 20));
      entTitle.setBounds(330,0,160,40);
      
      ingred.setBounds(50,110,258,40);
      
      instruc.setBounds(50,160,192,40);
      
      repName.setBounds(50,60,190,40);
// Adds components onto panel      
      entry.add(entTitle);
      entry.add(repName);
      entry.add(recipeName);
      entry.add(ingred);
      entry.add(instruc);
      entry.add(inst);     
      entry.add(ing);
      entry.add(cont);
      entry.add(rtn);
// Creates a root frame to hold the panel      
      root = new JFrame("Cooking Manual");     
      root.setSize(825, 300);
      root.setResizable(false);
      root.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      root.setLocationRelativeTo(null);
      root.setVisible(true);
      root.add(entry);
   }
      
    public void actionPerformed(ActionEvent e) {      
// Runs txtArr to begin populating the array      
      if(e.getSource()==cont){
         txtArr();
      }
// Returns to home screen      
      if(e.getSource() == rtn){        
         new Manual();
         root.dispose();
      }
   }
   
   public void txtArr(){
//checks if there is text within the starting textfields   
      if(ing.getText().equals("")|| inst.getText().equals("")||recipeName.getText().equals("")){
         JOptionPane.showMessageDialog(null,"Please use an integer in both text fields before proceding.","Input Error",JOptionPane.ERROR_MESSAGE);
      }else if(Integer.parseInt(ing.getText()) >= 21|| Integer.parseInt(inst.getText()) >= 21){
          JOptionPane.showMessageDialog(null,"Please use 20 or less ingredients or instructions.","Input Error",JOptionPane.ERROR_MESSAGE);     
      }else{
// changes the size of the root panel to fit txtBox array(s) and moves return/adds submit button     
         root.setSize(825,800);
         root.setLocationRelativeTo(null);   
         rtn.setBounds(710,700,90,30);
         entry.add(submit);
         cont.setVisible(false);
         recipeName.setEnabled(false);
         inst.setEnabled(false);
         ing.setEnabled(false);
// parses integers from the Ingredients text field and creates an array of text fields to print onto the screen 
  
         iNum = Integer.parseInt(ing.getText());
         JLabel[] sub = new JLabel[iNum];
         JTextField[] top = new JTextField[iNum];

// runs thorugh iNum to place ingredient text and label array onto panel         
      for(i = 0; i < iNum; i++){
         sub[i] = new JLabel("Ingredient: "+(i+1));
         top[i] = new JTextField("");
         entry.add(sub[i]);
         entry.add(top[i]);
         sub[i].setBounds(w,q,90,40);
         top[i].setBounds(r,c,100,30);   
         entry.revalidate();
           
// changing in y coordinate    
         q+= 40;
         c+= 40;
           
            if(q>=400||c>=400){
                q = 205;
                w += 200;
                r += 200;
                c = 210;
            }           
      }
// parses integers from the Instruction text field and creates an array of text fields to print onto the screen                 
      nNum = Integer.parseInt(inst.getText());
      JLabel[] botSub = new JLabel[nNum];
      JTextField[] bottom = new JTextField[nNum];
      
      for(k = 0; k < nNum; k++){
         botSub[k] = new JLabel("Instruction: "+(k+1));
         bottom[k] = new JTextField();
         entry.add(botSub[k]);
         entry.add(bottom[k]);       
         botSub[k].setBounds(o,p,90,40);
         bottom[k].setBounds(l,m,100,30);
         entry.revalidate();
         p+= 40;
         m+= 40;

         if(p>=650||m>=650){
             p = 480;
             o += 200;
             l += 200;
             m = 485;
         }     
      }
// sets action listener to submit button to start the file writer            
         submit.addActionListener(new ActionListener() {
         
            public void actionPerformed(ActionEvent f){           
               File file = new File("Recipes.txt");
               FileWriter fwr = null;         
                  try {
                     fwr = new FileWriter(file,true);
                     fwr.write(recipeName.getText().toLowerCase()+"\n"); 
                     fwr.write((iNum+nNum)+"\n");
  
                     for(i = 0; i < iNum; i++){ 
                        fwr.write("Ingredient: "+top[i].getText()+"\n");           
                     }
      
                     for(k = 0; k < nNum; k++){
                        fwr.write("instruction: "+bottom[k].getText()+"\n"); 
                     }
                     fwr.write("\n");
                     }catch(IOException e) {
                        e.printStackTrace();
                     }finally{
                     
                   try {                    
                     fwr.close();   
                   }catch(IOException e) {
                           e.printStackTrace();
                      }
                  }
              }
         });
      }   
   }     
}