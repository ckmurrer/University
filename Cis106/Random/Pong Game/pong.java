import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;
import java.util.Timer;

public class pong implements KeyListener {

   int playerScore = 0;
   int aiScore = 0;
   
   Timer bL = new TimerTask();
   //, bUD, bDD, bR, aU, aD;

   JPanel main = new JPanel();
   JFrame backFrame = new JFrame();
   
   JLabel pScore = new JLabel(String.valueOf(playerScore), SwingConstants.CENTER);
   JLabel aScore = new JLabel(String.valueOf(aiScore), SwingConstants.CENTER);
   JLabel topDivider = new JLabel();
   JLabel midDivider = new JLabel();
   JLabel player = new JLabel();
   JLabel ai = new JLabel();    
   JLabel ball = new JLabel();
   
   public static void main (String[] args){
      new pong();    
   }
   
   public pong(){
     
     aiMove();
     
     main.addKeyListener(this);
     main.setFocusable(true);
     main.setLayout(null);
   // score labels
      pScore.setBounds(94,7,60,39);  
      pScore.setFont(new Font("Times New Roman", Font.PLAIN, 40)); 
      pScore.setForeground(Color.white);
         
      aScore.setBounds(340,7,60,39);
      aScore.setFont(new Font("Times New Roman", Font.PLAIN, 40)); 
      aScore.setForeground(Color.white);
                   
   // side and score dividers
      midDivider.setBounds(249,0,3,52);
      midDivider.setOpaque(true);
      midDivider.setBackground(Color.white);
      
      topDivider.setBounds(0,52,500,3);
      topDivider.setOpaque(true);
      topDivider.setBackground(Color.white);
    
   // ball model
      ball.setBounds(245,238,11,11);
      ball.setOpaque(true);
      ball.setBackground(Color.green);
               
   // player model         
      player.setBounds(10,216,10,61);
      player.setOpaque(true);
      player.setBackground(Color.red);
        
   
   // ai model         
      ai.setBounds(474,216,10,61);
      ai.setOpaque(true);
      ai.setBackground(Color.red);
   
   // sets panel color     
      main.setBackground(Color.black);
  
   // adds players dividers and scores   
      main.add(aScore);
      main.add(pScore);  
      main.add(ball);        
      main.add(ai);
      main.add(player);
      main.add(midDivider);
      main.add(topDivider);

   // creation of frame that holds everything           
      backFrame = new JFrame();
      backFrame.setSize(500, 500);
      backFrame.setResizable(false);
      backFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      backFrame.setLocationRelativeTo(null);
      backFrame.setVisible(true);
      backFrame.add(main);   
   }
   
   
      public void ballMove(){
      
      
    /*  if(playerScore == 0 && aiScore == 0){
         
         
         
      }
      */
   }
   
   public void aiMove(){
  
   }
   
    @Override
    public void keyPressed(KeyEvent event) {
    
    // starts game/next round  
      if(event.getKeyCode() == KeyEvent.VK_SPACE){
         System.out.println("click");
      }
      
   // moves player up   
      if(event.getKeyCode() == KeyEvent.VK_UP){
         player.setLocation(player.getX(),player.getY()-5);
      }
      
   // moves player down    
      if(event.getKeyCode() == KeyEvent.VK_DOWN){
         player.setLocation(player.getX(),player.getY()+5);
      }
   }

   @Override
   public void keyReleased(KeyEvent event) {
      
   }
   
   @Override
   public void keyTyped(KeyEvent event) {
      
   }
    
}