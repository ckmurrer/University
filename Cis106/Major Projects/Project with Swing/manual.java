import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;
import java.util.Scanner;

public class manual extends JFrame implements ActionListener{
   boolean test = false;
   
   int teX;
   int ret;
   int iNum;
   int nNum;
   int x,y,i,k;
   int c = 210;
   int r = 90;
   int q = 205;
   int w = 0;
   int p = 480;
   int o = 0;
   int l = 90;
   int m = 485;
   
   JFrame root = new JFrame(); 

// panels
   JPanel how = new JPanel();
   JPanel entry = new JPanel();
   JPanel search = new JPanel();
   JPanel recipe = new JPanel();
   JPanel home = new JPanel();

// text entry
   JTextField ing = new JTextField();
   JTextField inst = new JTextField();
   JTextField ser = new JTextField();
   JTextField recipeName = new JTextField();
   
// button components
   JButton net = new JButton();
   JButton htg = new JButton();
   JButton adt = new JButton();
   JButton rtn = new JButton();
   JButton ext = new JButton();
   JButton ent = new JButton();
   JButton src = new JButton();
   JButton searchFile = new JButton();
   JButton submit = new JButton();

// labels
   JLabel ingred = new JLabel("Please enter how many ingredients there are.");
   JLabel instruc = new JLabel("How many steps are in the recipe.");
   JLabel entTitle = new JLabel("New Recipe Entry");
   JLabel ingTitle = new JLabel("Ingredients");
   JLabel insTitle = new JLabel("Instructions");
   JLabel head = new JLabel("Welcome to the Cooking Manual");
   JLabel desc = new JLabel();
   JLabel repName = new JLabel("Please enter the recipe name.");
   JLabel howHead = new JLabel("How To Use");
   JLabel howOne = new JLabel("For a new recipe hit the new recipe button.");
   JLabel howTwo = new JLabel("Then fill out the provided text fields and hit continue.");
   JLabel howThree = new JLabel("After hitting continue fill out the array of text fields and hit submit by doing so it will store all the data typed in a text document called Recipes.txt");
   JLabel howFour = new JLabel("When searching for a recipe hit the search button");
   JLabel howFive = new JLabel("Once at the search screen type in the text field the recipe you wish to find and hit submit.");
   JLabel howSix = new JLabel("If the recipe name is within the text document it will print out the full recipe, but if not found within the file it will pop up an error message.");
   
   public static void main(String[] args){
      new manual();
   }
   
   public manual(){
      rSize();
          
      home.setLayout(null);
      search.setLayout(null);
      entry.setLayout(null);
      recipe.setLayout(null);
          
// sets bounds and text for the components   
   // new entry screen
      ing.setBounds(313,115,100,30);
      inst.setBounds(247,165,100,30);
      recipeName.setBounds(225,65,100,30);
      
      net.setText("Continue");
      net.addActionListener(this);
      net.setBounds(550,110,90,30);
      
      submit.setText("Submit");
      submit.setBounds(650,700,60,30);
      entTitle.setFont(new Font(null, Font.PLAIN, 20));
      entTitle.setBounds(350,0,160,40);
      ingred.setBounds(50,110,258,40);
      instruc.setBounds(50,160,192,40);
      repName.setBounds(50,60,190,40);
      
      entry.add(entTitle);
      entry.add(repName);
      entry.add(recipeName);
      entry.add(ingred);
      entry.add(instruc);
      entry.add(inst);     
      entry.add(ing);
      entry.add(net);
      entry.add(submit);
   
   // how to screen
      howHead.setBounds(0,50,90,90);
      howOne.setBounds(0,0,0,0); 
      howTwo.setBounds(0,0,0,0);
      howThree.setBounds(0,0,0,0);
      howFour.setBounds(0,0,0,0);
      howFive.setBounds(0,0,0,0);
      howSix.setBounds(0,0,0,0);  
      
      how.add(howHead);
      how.add(howOne);
      how.add(howTwo);
      how.add(howThree);
      how.add(howFour);
      how.add(howFive);
      how.add(howSix);
      
   // search screen     
      desc.setBounds(0,0,150,90);
      desc.setText("Enter desired recipe name");
      
      ser.setBounds(100,90,90,40);
      
      searchFile.setText("Search");
      searchFile.setBounds(100,150,90,40);
      searchFile.addActionListener(this);
      
      search.add(searchFile);
      search.add(ser);
      search.add(desc);
      
   // recipe result screen
     
   // all screens but home
      rtn.setText("Return");
      rtn.addActionListener(this);
            
   // home screen 
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
      if(e.getSource()==rtn){
         bk();
      }      
      if(e.getSource()==ent){
         teX = 1;   
         rSize();
      }    
      if(e.getSource()==ext){
         teX = 2;   
         rSize();
      }       
      if(e.getSource()==src){
         teX = 3;   
         rSize();
      }      
      if(e.getSource()==htg){
         teX = 4;
         rSize();
      }
      if(e.getSource()==net){
         txtArr();
      }
      if(e.getSource()==searchFile){
         if(ser.getText().equals("")){
            JOptionPane.showMessageDialog(null,"Please enter a recipe before proceding.","Input Error",JOptionPane.ERROR_MESSAGE);
         } else{
            System.out.println("Searching for recipe");
         }    
      }
   }  
// creates the text field for entry
   public void txtArr(){
//checks if there is text within the starting textfields       
      if(ing.getText().equals("")|| inst.getText().equals("")||recipeName.getText().equals("")){
         JOptionPane.showMessageDialog(null,"Please use an integer in both text fields before proceding.","Input Error",JOptionPane.ERROR_MESSAGE);
      }else{
// changes the size of the root panel to fit txtBox array(s)      
         root.setSize(900,900);
         root.setLocationRelativeTo(null);   
         net.setVisible(false);
// parses integers from the text fields and creates an array of text fields to print onto the screen      
         iNum = Integer.parseInt(ing.getText());
         JLabel[] sub = new JLabel[iNum];
         JTextField[] top = new JTextField[iNum];
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
// parses integers from the text fields and creates an array of text fields to print onto the screen                 
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
            
               if(p>=850||m>=850){
                  p = 370;
                  o += 200;
                  l += 200;
                  m = 370;
               } 
            }
// sets action listener to submit button to start the file writer            
           submit.addActionListener(new ActionListener() {
               public void actionPerformed(ActionEvent f){           
                  
                    File file = new File("Recipes.txt");

                    FileWriter fwr = null;
                  try {
                    fwr = new FileWriter(file,true);
                    fwr.write(recipeName.getText()+"\n"); 
                    fwr.write((iNum+nNum)+"\n");
                    
                  for(i = 0; i < iNum; i++){ 
                    fwr.write("Ingredient: "+top[i].getText()+"\n");
                 
                  }
                   for(k = 0; k < nNum; k++){
                    fwr.write("instruction: "+bottom[k].getText()+"\n"); 
                    }
                    
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
   
// file reader to be called when search button is pressed   
   public void readTxt(){
      
        
   }
       
// resizes the window to match what panel is being used   
   public void rSize(){
   
      switch(teX){
            
         case 1:             
            root.getContentPane().remove(home);
            root.revalidate();
            root.add(entry);
            entry.add(rtn);
            rtn.setBounds(700,750,95,40);
            ret = 1;
            root.setSize(900, 300);
            root.setLocationRelativeTo(null);   
            break;
            
         case 2:       
            System.exit(0);          
            break;
            
         case 3:
            root.getContentPane().remove(home);
            root.revalidate();
            root.add(search);
            search.add(rtn);
            rtn.setBounds(0,230,95,40);
            ret = 2;
            root.setSize(300, 300);
            root.setLocationRelativeTo(null);   
            break;
            
         case 4:
            root.getContentPane().remove(home);
            root.revalidate();
            root.add(how);
            how.add(rtn);
            rtn.setBounds(0,230,95,40);
            ret = 3;
            how.setBackground(Color.cyan);
            root.setSize(500, 500);
            root.setLocationRelativeTo(null);           
            break;
      }        
   } 
   
// sets the return button on each frame to bring back to home   
   public void bk(){
   
      switch(ret){
      
         case 1: 
            root.setSize(400,300);
            root.getContentPane().remove(entry);
            root.revalidate();
            root.setLocationRelativeTo(null);
            root.add(home);
            break;
         
         case 2:
            root.setSize(400,300);
            root.getContentPane().remove(search);
            root.revalidate();
            root.setLocationRelativeTo(null);
            root.add(home);
            break;
         
         case 3:
            root.getContentPane().remove(how);
            root.revalidate();
            root.add(home);
            root.setSize(400,300);
            root.setLocationRelativeTo(null);
            break;
      } 
   }
}