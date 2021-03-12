// **********************************************************************************
// Title: Mazes
// Author: Cody Murrer
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: MazeOne.java
// Description: The first and easiest maze of three different mazes 
// **********************************************************************************
import javafx.scene.control.Label;
import javafx.scene.text.Text;
import javafx.stage.WindowEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.input.KeyCode;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.application.Platform;

import java.io.File;
import java.io.IOException;
import java.util.Random;
import java.util.Stack;
import java.util.Timer;
import java.util.TimerTask;

public class MazeOne{

Boolean left = false;
Boolean right = false;
Boolean up = false; 
Boolean down = false;

Boolean clockStart = false;
Boolean clockStop = false;

Timer clockTicks;

int  sec, min = 0;
int stopNow = 0;

Button btnReturn = new Button();

Label lblTimerBorder = new Label();
Label lblTimerDesc = new Label("Time Spent");

Text txtPlayerTimer = new Text(String.format("%02d:%02d", min,sec));

Rectangle q1 = new Rectangle();
Rectangle q2 = new Rectangle();
Rectangle q3 = new Rectangle();
Rectangle q4 = new Rectangle();

Rectangle rectPlayer = new Rectangle();
Rectangle rectStart = new Rectangle();
Rectangle rectEnd = new Rectangle();

Rectangle[] rightVertWalls = new Rectangle[50];
Rectangle[] leftVertWalls = new Rectangle[50];

Rectangle[] botHorizWalls = new Rectangle[42];
Rectangle[] topHorizWalls = new Rectangle[54];

private Pane mazeOnePane;

   public static void main(String[] args){
      new MazeOne();
   }
   
   public MazeOne(){
	   
      mazeOnePane = new Pane();
      
      winCondition();
      endPos();
      startPos();
      walls();
      closing();
      timeSave();
       
      btnReturn.setText("Return");
      btnReturn.setTranslateX(50);
      btnReturn.setTranslateY(565);
      btnReturn.setPrefHeight(30);
      btnReturn.setPrefWidth(90);
      
      lblTimerBorder.setPrefWidth(612);
      lblTimerBorder.setPrefHeight(75);
      lblTimerBorder.setStyle("-fx-border-color: Black;");
      lblTimerBorder.setTranslateX(-1);
      lblTimerBorder.setTranslateY(545);
      
      lblTimerDesc.setPrefWidth(150);
      lblTimerDesc.setPrefHeight(20);
      lblTimerDesc.setFont(new Font("Arial", 20));
      lblTimerDesc.setTranslateX(5);
      lblTimerDesc.setTranslateY(550);
      
      txtPlayerTimer.setFont(new Font("Arial", 20));
      txtPlayerTimer.setTranslateX(20);
      txtPlayerTimer.setTranslateY(590);
    
      rectPlayer.setWidth(15);
      rectPlayer.setHeight(15);
      rectPlayer.setY(520);
      rectPlayer.setX(310);
      rectPlayer.setFocusTraversable(true);  
      rectPlayer.setFill(Color.FUCHSIA);
  
// adds objects to the screen      
      mazeOnePane.getChildren().addAll(txtPlayerTimer,lblTimerDesc,lblTimerBorder,rectStart,rectEnd);
      mazeOnePane.getChildren().add(rectPlayer);
      
// sets color, and adds Left and Right vertical walls       
      for(int i = 0; i< leftVertWalls.length; i++) {
    	  leftVertWalls[i].setFill(Color.BLACK);
    	  rightVertWalls[i].setFill(Color.BLACK);
    	  mazeOnePane.getChildren().add(leftVertWalls[i]);
    	  mazeOnePane.getChildren().add(rightVertWalls[i]);
      
      }
      
// sets color, and adds Top horizontal walls      
      for(int k = 0; k < topHorizWalls.length; k++) {
    	  topHorizWalls[k].setFill(Color.BLACK);
    	  mazeOnePane.getChildren().add(topHorizWalls[k]);
      }
      
// sets color, and adds Bottom horizontal walls       
      for(int j = 0; j < botHorizWalls.length; j++) {
    	  botHorizWalls[j].setFill(Color.BLACK);
    	  mazeOnePane.getChildren().add(botHorizWalls[j]);
      }
   	  Movement();
   }
   
// Timer that ticks once a second to count up the clock   
   class clockStart extends TimerTask {

	   @Override
	   public void run() {		   
		   txtPlayerTimer.setText(String.format("%02d:%02d", min,sec));
		   sec++;
		   if(sec >= 59) {
			   sec = 0;
			   min++;
		   }
		   clockTicks = new Timer();
		   clockTicks.schedule(new clockStart(), 1000);
	   }
   }

// Stop method for the timer task
   public void clockStop() {
	   if(clockStop == true) {
		   clockTicks.cancel();
	   }
   }

 // pacman twist where you have to collect 4 rectangles to unlock the ending of the maze gets sent into a queue 
 // when rectangle or circle has been collected it removes from queue and will either change colors or be removed from the map
   public void winCondition() {
	   Random rnd = new Random();
	   RectStack rs = new RectStack();
	 //  int n = rnd.nextInt(51);
	  int n = 25; 
	   if(n <= 25) {
		   
		   q1.setY(116);
		   q1.setX(9);
		   q1.setWidth(15);
		   q1.setHeight(15);
		   q1.setFill(Color.GREEN);
		   
		   q2.setY(35);
		   q2.setX(525);
		   q2.setWidth(15);
		   q2.setHeight(15);
		   q2.setFill(Color.BLUE);
		   
		   q3.setY(335);
		   q3.setX(40);
		   q3.setWidth(15);
		   q3.setHeight(15);
		   q3.setFill(Color.ORANGE);
		   
		   q4.setY(387);
		   q4.setX(525);
		   q4.setHeight(15);
		   q4.setWidth(15);
		   q4.setFill(Color.RED);
		   
		   mazeOnePane.getChildren().addAll(q4);
		   
		   rs.push(q4);
		   rs.push(q3);
		   rs.push(q2);
		   rs.push(q1);

		   System.out.println("under 25");
	   }else if(n >= 26) {
		   
		   q1.setY(0);
		   q1.setX(0);
		   q1.setWidth(15);
		   q1.setHeight(15);
		   
		   q2.setY(0);
		   q2.setX(0);
		   q2.setWidth(15);
		   q2.setHeight(15);
		   
		   q3.setY(0);
		   q3.setX(0);
		   q3.setWidth(15);
		   q3.setHeight(15);
		   
		   q4.setY(0);
		   q4.setX(0);
		   q4.setHeight(15);
		   
		   mazeOnePane.getChildren().addAll(q1,q2,q3,q4);
		   System.out.println("over 26");
	   }
   }
   
// Starting position of the maze   
   public void startPos() {
	   rectStart.setWidth(27);
	   rectStart.setHeight(28);
	   rectStart.setY(516);
	   rectStart.setX(307);
	   rectStart.setFill(Color.LIGHTGREEN);
   }
   
// Ending position of the maze   
   public void endPos() {
	   rectEnd.setWidth(27);
	   rectEnd.setHeight(28);
	   rectEnd.setY(4);
	   rectEnd.setX(277);
	   rectEnd.setFill(Color.LIGHTSALMON);
   }
   
// movement for player object with a switch and keycode   
   public void Movement() {
	   rectPlayer.setOnKeyPressed(e -> {  
		   CollisionDetection();
		   
		   KeyCode kp = e.getCode();       
	       switch (kp) {      
	          case S:
	        	  if(rectPlayer.getY() <= 525){ 	        		 
	        		 rectPlayer.setY(rectPlayer.getY() + 5);  

// sets direction of motion for the player	        		 
	        		 down = true;
	        		 up = false;
	        		 left = false;
	        		 right = false;
	        	  } 
	          break;
	         
	          case W: 	        	  	            	
	        	  if(rectPlayer.getY() >= 5){ 	        		  
	        		  rectPlayer.setY(rectPlayer.getY() - 5); 

// sets direction of motion for the player	
	        		  up = true;
	        		  down = false;
	        		  left = false;
	        		  right= false;
	        	  } 
	          break;
	         
	          case A:
	        	  if(rectPlayer.getX() >= 5){ 
	        		  rectPlayer.setX(rectPlayer.getX() - 5);    

// sets direction of motion for the player		        		  
	        		  left = true;
	        		  right = false;
	        		  up = false;
	        		  down = false;
	        	  }
	          break;
	     
	          case D: 
	        	  if(rectPlayer.getX() <= 590){   
	        		  rectPlayer.setX(rectPlayer.getX() + 5);        
	        		  
// sets direction of motion for the player		        		  
	        		  right = true; 
	        		  left = false;
	        		  up = false;
	        		  down = false;
	        	  }  	
	          break;
		default:
			break;
	       }
	   }); 
   }   
   
// writes to a file to save the time of the user    
   public void timeSave() {
	   File mOneTimes = new File("MazeOneTimes.txt");
	   if(!mOneTimes.exists()) {
		   try {
			   mOneTimes.createNewFile();
		   } catch (IOException e) {
			   e.printStackTrace();
		   }
	   }
   }
   
// detects collision between player and walls    
   public void CollisionDetection(){
	   RectStack rs = new RectStack();
// left and right vertical wall collision	   
	   for(int i = 0; i < leftVertWalls.length; i++) {   
		   if(up == true) {
			   if(rectPlayer.getBoundsInParent().intersects(leftVertWalls[i].getBoundsInParent())||rectPlayer.getBoundsInParent().intersects(rightVertWalls[i].getBoundsInParent())) {
				   rectPlayer.setY(rectPlayer.getY()+5);
			   }
		   }else if(down == true) {
			   if(rectPlayer.getBoundsInParent().intersects(leftVertWalls[i].getBoundsInParent())||rectPlayer.getBoundsInParent().intersects(rightVertWalls[i].getBoundsInParent())) {
				   rectPlayer.setY(rectPlayer.getY()-5);
			   }
		   }else if(left == true) {
			   if(rectPlayer.getBoundsInParent().intersects(leftVertWalls[i].getBoundsInParent())||rectPlayer.getBoundsInParent().intersects(rightVertWalls[i].getBoundsInParent())) {
				   rectPlayer.setX(rectPlayer.getX()+5);
			   }
		   }else if(right == true) {
			   if(rectPlayer.getBoundsInParent().intersects(leftVertWalls[i].getBoundsInParent())||rectPlayer.getBoundsInParent().intersects(rightVertWalls[i].getBoundsInParent())) {
				   rectPlayer.setX(rectPlayer.getX()-5);
			   }
		   }
	   }

// top horizontal walls collision	   
	   for(int k = 0; k < topHorizWalls.length;k++) {
		   if(up == true) {
			   if(rectPlayer.getBoundsInParent().intersects(topHorizWalls[k].getBoundsInParent())) {
				   rectPlayer.setY(rectPlayer.getY()+0);
			   }
		   }else if(down == true) {
			   if(rectPlayer.getBoundsInParent().intersects(topHorizWalls[k].getBoundsInParent())) {
				   rectPlayer.setY(rectPlayer.getY()-0);
			   }
		   }else if(left == true) {
			   if(rectPlayer.getBoundsInParent().intersects(topHorizWalls[k].getBoundsInParent())) {
				   rectPlayer.setX(rectPlayer.getX()+0);
			   }
		   }else if(right == true) {
			   if(rectPlayer.getBoundsInParent().intersects(topHorizWalls[k].getBoundsInParent())) {
				   rectPlayer.setX(rectPlayer.getX()-0);
			   }
		   }
	   }
	   
// bottom horizontal wall collision	   
	   for(int j = 0; j < botHorizWalls.length; j++ ) {
		   if(up == true) {
			   if(rectPlayer.getBoundsInParent().intersects(botHorizWalls[j].getBoundsInParent())) {
				   rectPlayer.setY(rectPlayer.getY()+0);
			   }
		   }else if(down == true) {
			   if(rectPlayer.getBoundsInParent().intersects(botHorizWalls[j].getBoundsInParent())) {
				   rectPlayer.setY(rectPlayer.getY()-0);
			   }
		   }else if(left == true) {
			   if(rectPlayer.getBoundsInParent().intersects(botHorizWalls[j].getBoundsInParent())) {
				   rectPlayer.setX(rectPlayer.getX()+0);
			   }
		   }else if(right == true) {
			   if(rectPlayer.getBoundsInParent().intersects(botHorizWalls[j].getBoundsInParent())) {
				   rectPlayer.setX(rectPlayer.getX()-0);
			   }
		   }
	   }
	   
	   if(up == true || down == true || left == true || right == true) {
		   if(rectPlayer.getBoundsInParent().intersects(q1.getBoundsInParent())) {
			   
			   mazeOnePane.getChildren().remove(q1);
			   q1.setY(-10);
			   q1.setX(-10);
			   System.out.println("got one");
			   
			   mazeOnePane.getChildren().remove(q1);
			   rs.pop();
			   
		   }else if(rectPlayer.getBoundsInParent().intersects(q2.getBoundsInParent())) {
			   mazeOnePane.getChildren().remove(q2);
			   q2.setY(-10);
			   q2.setX(-10);
			   System.out.println("got two");
			   mazeOnePane.getChildren().add(q1);
			   mazeOnePane.getChildren().remove(q2);
            
			   rs.pop();
			   
		   }else if(rectPlayer.getBoundsInParent().intersects(q3.getBoundsInParent())) {
			   mazeOnePane.getChildren().remove(q3);
			   q3.setY(-10);
			   q3.setX(-10);
			   System.out.println("got three");
			   
			   mazeOnePane.getChildren().add(q2);
			   mazeOnePane.getChildren().remove(q3);
			   rs.pop();
			   
		   }else if(rectPlayer.getBoundsInParent().intersects(q4.getBoundsInParent())) {
			   mazeOnePane.getChildren().remove(q4);
			   q4.setY(-10);
			   q4.setX(-10);
			   System.out.println("got four");
			   
			   mazeOnePane.getChildren().add(q3);
			   mazeOnePane.getChildren().remove(q4);
			   
            rs.pop();
		   }   
	   }

// Starts the clock with a collision with startPos	   
	   if(clockStart == false) {
		   if(!(rectPlayer.getBoundsInParent().intersects(rectStart.getBoundsInParent())) && !(rectPlayer.getBoundsInParent().intersects(rectEnd.getBoundsInParent()))) {
			   clockStart = true;			   
			   clockTicks = new Timer();
			   clockTicks.schedule(new clockStart(), 1000);
			   System.out.println("clock is ticking");
		   }

// Stops the clock with a collision endPos	   
	   }else if (clockStart == true) {
		   if(rectPlayer.getBoundsInParent().intersects(rectEnd.getBoundsInParent()) || rectPlayer.getBoundsInParent().intersects(rectStart.getBoundsInParent())) {
			   clockStart = false;
			   clockStop = true;
			   clockStop();
			   rectPlayer.setY(rectPlayer.getY()-15);
			   FileWrite.display("test", "Congradulations your time was","MazeOneTimes.txt",min,sec);
		   }
	   }
   }
   
// walls of the maze   
   public void walls() {
// vert walls left    
		   leftVertWalls[0] = new Rectangle(0,0,4,546);						// outer wall left down
		   leftVertWalls[1] = new Rectangle(0,544,337,4); 					// outer wall bottom left to start
		   leftVertWalls[2] = new Rectangle(0,0,310,4);  					// outer wall top left to end 
		   leftVertWalls[3] = new Rectangle(304,0,307,4);  					// outer wall end to top right
		   leftVertWalls[4] = new Rectangle(606,0,4,546);  					// outer wall right down
		   leftVertWalls[5] = new Rectangle(334,544,280,4); 				// outer wall start to bottom right 
		   leftVertWalls[6] = new Rectangle(31,28,4,112);					// vertical left row 1 column 1
		   leftVertWalls[7] = new Rectangle(31,163,4,112);					// vertical left row 2 column 1
		   leftVertWalls[8] = new Rectangle(31,326,4,112);					// vertical left row 3 column 1
		   leftVertWalls[9] = new Rectangle(31,489,4,31);					// vertical left row 4 column 1
		   leftVertWalls[10] = new Rectangle(61,28,4,30);					// vertical left row 1 column 2
		   leftVertWalls[11] = new Rectangle(61,109,4,31);					// vertical left row 2 column 2
		   leftVertWalls[12] = new Rectangle(61,190,4,58);					// vertical left row 3 column 2
		   leftVertWalls[13] = new Rectangle(61,299,4,58);					// vertical left row 4 column 2
		   leftVertWalls[14] = new Rectangle(61,407,4,86);					// vertical left row 5 column 2
		   leftVertWalls[15] = new Rectangle(91,27,4,31);					// vertical left row 1 column 3
		   leftVertWalls[16] = new Rectangle(91,109,4,85);					// vertical left row 2 column 3
		   leftVertWalls[17] = new Rectangle(91,381,4,139);					// vertical left row 3 column 3
		   leftVertWalls[18] = new Rectangle(122,0,4,31);					// vertical left row 1 column 4
		   leftVertWalls[19] = new Rectangle(122,55,4,85);					// vertical left row 2 column 4
		   leftVertWalls[20] = new Rectangle(122,190,4,58);					// vertical left row 3 column 4
		   leftVertWalls[21] = new Rectangle(122,272,4,31);					// vertical left row 4 column 4
		   leftVertWalls[22] = new Rectangle(122,407,4,85);					// vertical left row 5 column 4
		   leftVertWalls[23] = new Rectangle(122,516,4,28);					// vertical left row 6 column 4
		   leftVertWalls[24] = new Rectangle(152,82,4,31);					// vertical left row 1 column 5
		   leftVertWalls[25] = new Rectangle(152,136,4,30);					// vertical left row 2 column 5
		   leftVertWalls[26] = new Rectangle(152,299,4,31);					// vertical left row 3 column 5
		   leftVertWalls[27] = new Rectangle(152,354,4,31);					// vertical left row 4 column 5
		   leftVertWalls[28] = new Rectangle(152,489,4,31);					// vertical left row 5 column 5
		   leftVertWalls[29] = new Rectangle(182,28,4,30);					// vertical left row 1 column 6
		   leftVertWalls[30] = new Rectangle(182,109,4,30);					// vertical left row 2 column 6
		   leftVertWalls[31] = new Rectangle(182,163,4,30);					// vertical left row 3 column 6 
		   leftVertWalls[32] = new Rectangle(182,217,4,86);					// vertical left row 4 column 6 
		   leftVertWalls[33] = new Rectangle(182,354,4,84);					// vertical left row 5 column 6
		   leftVertWalls[34] = new Rectangle(182,462,4,58);					// vertical left row 6 column 6
		   leftVertWalls[35] = new Rectangle(213,28,4,85);					// vertical left row 1 column 7
		   leftVertWalls[36] = new Rectangle(213,137,4,85);					// vertical left row 2 column 7
		   leftVertWalls[37] = new Rectangle(213,299,4,139);				// vertical left row 3 column 7
		   leftVertWalls[38] = new Rectangle(243,82,4,58);					// vertical left row 1 column 8
		   leftVertWalls[39] = new Rectangle(243,163,4,85);					// vertical left row 2 column 8
		   leftVertWalls[40] = new Rectangle(243,272,4,31);					// vertical left row 3 column 8
		   leftVertWalls[41] = new Rectangle(243,327,4,30);					// vertical left row 4 column 8
		   leftVertWalls[42] = new Rectangle(243,407,4,58);					// vertical left row 5 column 8
		   leftVertWalls[43] = new Rectangle(243,516,4,28);					// vertical left row 6 column 8
		   leftVertWalls[44] = new Rectangle(273,0,4,58);					// vertical left row 1 column 9
		   leftVertWalls[45] = new Rectangle(273,109,4,85);					// vertical left row 2 column 9
		   leftVertWalls[46] = new Rectangle(273,299,4,31);					// vertical left row 3 column 9
		   leftVertWalls[47] = new Rectangle(273,381,4,30);					// vertical left row 4 column 9
		   leftVertWalls[48] = new Rectangle(273,435,4,30);					// vertical left row 5 column 9
		   leftVertWalls[49] = new Rectangle(273,489,4,31);					// vertical left row 6 column 9

// vertical walls right	
		   rightVertWalls[0] = new Rectangle(304,28,4,85);					// vertical right row 1 column 1
		   rightVertWalls[1] = new Rectangle(304,136,4,30);     			// vertical right row 2 column 1
		   rightVertWalls[2] = new Rectangle(304,190,4,31);     			// vertical right row 3 column 1
		   rightVertWalls[3] = new Rectangle(304,271,4,114);    			// vertical right row 4 column 1
		   rightVertWalls[4] = new Rectangle(304,435,4,58);     			// vertical right row 5 column 1
		   rightVertWalls[5] = new Rectangle(304,516,4,30);     			// vertical right row 6 column 1
		   rightVertWalls[6] = new Rectangle(334,82,4,31);      			// vertical right row 1 column 2
		   rightVertWalls[7] = new Rectangle(334,163,4,31);     			// vertical right row 2 column 2
		   rightVertWalls[8] = new Rectangle(334,217,4,31);     			// vertical right row 3 column 2
		   rightVertWalls[9] = new Rectangle(334,299,4,31);     			// vertical right row 4 column 2
	 	   rightVertWalls[10] = new Rectangle(334,381,4,30);    			// vertical right row 5 column 2
		   rightVertWalls[11] = new Rectangle(334,489,4,30);    			// vertical right row 6 column 2
		   rightVertWalls[12] = new Rectangle(364,55,4,81);    				// vertical right row 1 column 3
		   rightVertWalls[13] = new Rectangle(364,245,4,58);  				// vertical right row 2 column 3
		   rightVertWalls[14] = new Rectangle(364,354,4,31);   				// vertical right row 3 column 3
		   rightVertWalls[15] = new Rectangle(364,407,4,86);    			// vertical right row 4 column 3
		   rightVertWalls[16] = new Rectangle(394,0,4,58);     				// vertical right row 1 column 4
		   rightVertWalls[17] = new Rectangle(394,82,4,31);     			// vertical right row 2 column 4
		   rightVertWalls[18] = new Rectangle(394,136,4,112);               // vertical right row 3 column 4
		   rightVertWalls[19] = new Rectangle(394,299,4,58);                // vertical right row 4 column 4
		   rightVertWalls[20] = new Rectangle(394,435,4,30);                // vertical right row 5 column 4
		   rightVertWalls[21] = new Rectangle(425,28,4,58);                	// vertical right row 1 column 5 
		   rightVertWalls[22] = new Rectangle(425,109,4,31);                // vertical right row 2 column 5
		   rightVertWalls[23] = new Rectangle(425,163,4,31);                // vertical right row 3 column 5
		   rightVertWalls[24] = new Rectangle(425,245,4,113);               // vertical right row 4 column 5
		   rightVertWalls[25] = new Rectangle(425,407,4,113);               // vertical right row 5 column 5
		   rightVertWalls[26] = new Rectangle(455,0,4,58);                	// vertical right row 1 column 6
		   rightVertWalls[27] = new Rectangle(455,82,4,84);                	// vertical right row 2 column 6
		   rightVertWalls[28] = new Rectangle(455,190,4,58);                // vertical right row 3 column 6
		   rightVertWalls[29] = new Rectangle(455,354,4,30);                // vertical right row 4 column 6
	 	   rightVertWalls[30] = new Rectangle(455,489,4,31);                // vertical right row 5 column 6
		   rightVertWalls[31] = new Rectangle(485,81,4,59);                	// vertical right row 1 column 7
		   rightVertWalls[32] = new Rectangle(485,163,4,31);                // vertical right row 2 column 7
		   rightVertWalls[33] = new Rectangle(485,245,4,58);                // vertical right row 3 column 7
		   rightVertWalls[34] = new Rectangle(485,407,4,31);                // vertical right row 4 column 7
		   rightVertWalls[35] = new Rectangle(485,462,4,30);                // vertical right row 5 column 7
		   rightVertWalls[36] = new Rectangle(485,516,4,31);                // vertical right row 6 column 7
		   rightVertWalls[37] = new Rectangle(516,28,4,30);                	// vertical right row 1 column 8
		   rightVertWalls[38] = new Rectangle(516,82,4,31);                	// vertical right row 2 column 8
		   rightVertWalls[39] = new Rectangle(516,136,4,85);                // vertical right row 3 column 8
		   rightVertWalls[40] = new Rectangle(516,272,4,139);               // vertical right row 4 column 8
		   rightVertWalls[41] = new Rectangle(516,489,4,31);                // vertical right row 5 column 8
		   rightVertWalls[42] = new Rectangle(546,55,4,58);                	// vertical right row 1 column 9
		   rightVertWalls[43] = new Rectangle(546,190,4,58);                // vertical right row 2 column 9
		   rightVertWalls[44] = new Rectangle(546,326,4,85);                // vertical right row 3 column 9
		   rightVertWalls[45] = new Rectangle(546,435,4,31);                // vertical right row 4 column 9
		   rightVertWalls[46] = new Rectangle(576,109,4,57);                // vertical right row 1 column 10
		   rightVertWalls[47] = new Rectangle(576,217,4,86);                // vertical right row 2 column 10
		   rightVertWalls[48] = new Rectangle(576,406,4,87);                // vertical right row 3 column 10
		   rightVertWalls[49] = new Rectangle();                // extra

// top horizontal walls	   
		   topHorizWalls[0] = new Rectangle(31,27,34,4);					// horizontal top row 1 horizontal 1
		   topHorizWalls[1] = new Rectangle(122,27,34,4);					// horizontal top row 1 horizontal 2
		   topHorizWalls[2] = new Rectangle(182,27,64,4);					// horizontal top row 1 horizontal 3
		   topHorizWalls[3] = new Rectangle(304,27,63,4);					// horizontal top row 1 horizontal 4
		   topHorizWalls[4] = new Rectangle(486,27,93,4);					// horizontal top row 1 horizontal 5
		   topHorizWalls[5] = new Rectangle(91,54,35,4);					// horizontal top row 2 horizontal 1 
		   topHorizWalls[6] = new Rectangle(151,54,35,4);					// horizontal top row 2 horizontal 2
		   topHorizWalls[7] = new Rectangle(242,54,35,4);					// horizontal top row 2 horizontal 3
		   topHorizWalls[8] = new Rectangle(304,54,125,4);					// horizontal top row 2 horizontal 4
		   topHorizWalls[9] = new Rectangle(455,54,34,4);					// horizontal top row 2 horizontal 5
		   topHorizWalls[10] = new Rectangle(516,54,120,4);					// horizontal top row 2 horizontal 6
		   topHorizWalls[11] = new Rectangle(31,82,95,4);					// horizontal top row 3 horizontal 1
		   topHorizWalls[12] = new Rectangle(183,82,34,4);					// horizontal top row 3 horizontal 2
		   topHorizWalls[13] = new Rectangle(243,82,65,4);					// horizontal top row 3 horizontal 3
		   topHorizWalls[14] = new Rectangle(425,82,34,4);					// horizontal top row 3 horizontal 4
		   topHorizWalls[15] = new Rectangle(575,82,35,4);					// horizontal top row 3 horizontal 5
		   topHorizWalls[16] = new Rectangle(61,109,34,4);					// horizontal top row 4 horizontal 1
		   topHorizWalls[17] = new Rectangle(122,109,95,4);					// horizontal top row 4 horizontal 2
		   topHorizWalls[18] = new Rectangle(304,109,34,4);					// horizontal top row 4 horizontal 3
		   topHorizWalls[19] = new Rectangle(394,109,35,4);					// horizontal top row 4 horizontal 4
		   topHorizWalls[20] = new Rectangle(485,109,35,4);					// horizontal top row 4 horizontal 5
		   topHorizWalls[21] = new Rectangle(546,109,34,4);					// horizontal top row 4 horizontal 6
		   topHorizWalls[22] = new Rectangle(0,136,35,4);					// horizontal top row 5 horizontal 1
		   topHorizWalls[23] = new Rectangle(213,136,34,4);					// horizontal top row 5 horizontal 2
		   topHorizWalls[24] = new Rectangle(273,136,95,4);					// horizontal top row 5 horizontal 3
		   topHorizWalls[25] = new Rectangle(394,136,35,4);					// horizontal top row 5 horizontal 4
		   topHorizWalls[26] = new Rectangle(455,136,34,4);					// horizontal top row 5 horizontal 5
		   topHorizWalls[27] = new Rectangle(516,136,34,4);					// horizontal top row 5 horizontal 6
		   topHorizWalls[28] = new Rectangle(31,162,125,4);					// horizontal top row 6 horizontal 1
		   topHorizWalls[29] = new Rectangle(182,162,35,4);					// horizontal top row 6 horizontal 2
		   topHorizWalls[30] = new Rectangle(243,162,34,4);					// horizontal top row 6 horizontal 3
		   topHorizWalls[31] = new Rectangle(364,162,34,4);					// horizontal top row 6 horizontal 4
		   topHorizWalls[32] = new Rectangle(425,162,34,4);					// horizontal top row 6 horizontal 5
		   topHorizWalls[33] = new Rectangle(516,162,64,4);					// horizontal top row 6 horizontal 6
		   topHorizWalls[34] = new Rectangle(91,190,95,4);					// horizontal top row 7 horizontal 1
		   topHorizWalls[35] = new Rectangle(304,190,64,4);					// horizontal top row 7 horizontal 2
		   topHorizWalls[36] = new Rectangle(455,190,34,4);					// horizontal top row 7 horizontal 3
		   topHorizWalls[37] = new Rectangle(546,190,34,4);					// horizontal top row 7 horizontal 4
		   topHorizWalls[38] = new Rectangle(61,217,34,4);					// horizontal top row 8 horizontal 1
		   topHorizWalls[39] = new Rectangle(152,217,34,4);					// horizontal top row 8 horizontal 2
		   topHorizWalls[40] = new Rectangle(243,217,65,4);					// horizontal top row 8 horizontal 3
		   topHorizWalls[41] = new Rectangle(334,217,33,4);					// horizontal top row 8 horizontal 4
		   topHorizWalls[42] = new Rectangle(394,217,65,4);					// horizontal top row 8 horizontal 5
		   topHorizWalls[43] = new Rectangle(485,217,35,4);					// horizontal top row 8 horizontal 6
		   topHorizWalls[44] = new Rectangle(576,217,34,4);					// horizontal top row 8 horizontal 7
		   topHorizWalls[45] = new Rectangle(61,244,94,4);					// horizontal top row 9 horizontal 1
		   topHorizWalls[46] = new Rectangle(182,244,65,4);					// horizontal top row 9 horizontal 2
		   topHorizWalls[47] = new Rectangle(274,244,124,4);				// horizontal top row 9 horizontal 3
		   topHorizWalls[48] = new Rectangle(455,244,95,4);					// horizontal top row 9 horizontal 4
		   topHorizWalls[49] = new Rectangle(31,271,63,4);					// horizontal top row 10 horizontal 1 
		   topHorizWalls[50] = new Rectangle(122,271,64,4);					// horizontal top row 10 horizontal 2
		   topHorizWalls[51] = new Rectangle(212,271,125,4);				// horizontal top row 10 horizontal	3
		   topHorizWalls[52] = new Rectangle(394,271,64,4);					// horizontal top row 10 horizontal 4
		   topHorizWalls[53] = new Rectangle(516,271,64,4);					// horizontal top row 10 horizontal 5
		   
		   
	// bottom horizontal walls	   
		   botHorizWalls[0] = new Rectangle(0,299,65,4);					// horizontal bottom row 1 horizontal
		   botHorizWalls[1] = new Rectangle(92,299,34,4);					// horizontal bottom row 1 horizontal
		   botHorizWalls[2] = new Rectangle(243,299,34,4);					// horizontal bottom row 1 horizontal
		   botHorizWalls[3] = new Rectangle(334,299,34,4);					// horizontal bottom row 1 horizontal	
		   botHorizWalls[4] = new Rectangle(454,299,34,4);					// horizontal bottom row 1 horizontal
		   botHorizWalls[5] = new Rectangle(516,299,34,4);					// horizontal bottom row 1 horizontal
		   botHorizWalls[6] = new Rectangle(61,326,156,4);					// horizontal bottom row 2 horizontal
		   botHorizWalls[7] = new Rectangle(334,326,64,4);					// horizontal bottom row 2 horizontal
		   botHorizWalls[8] = new Rectangle(455,326,64,4);					// horizontal bottom row 2 horizontal
		   botHorizWalls[9] = new Rectangle(576,326,34,4);					// horizontal bottom row 2 horizontal
		   botHorizWalls[10] = new Rectangle(31,354,34,4);					// horizontal bottom row 3 horizontal
		   botHorizWalls[11] = new Rectangle(92,354,64,4);					// horizontal bottom row 3 horizontal
		   botHorizWalls[12] = new Rectangle(243,354,125,4);				// horizontal bottom row 3 horizontal
		   botHorizWalls[13] = new Rectangle(394,354,94,4);					// horizontal bottom row 3 horizontal
		   botHorizWalls[14] = new Rectangle(546,354,33,4);					// horizontal bottom row 3 horizontal
		   botHorizWalls[15] = new Rectangle(61,381,94,4);					// horizontal bottom row 4 horizontal
		   botHorizWalls[16] = new Rectangle(213,381,64,4);					// horizontal bottom row 4 horizontal
		   botHorizWalls[17] = new Rectangle(334,381,95,4);					// horizontal bottom row 4 horizontal
		   botHorizWalls[18] = new Rectangle(485,381,35,4);					// horizontal bottom row 4 horizontal
		   botHorizWalls[19] = new Rectangle(575,381,35,4);					// horizontal bottom row 4 horizontal
		   botHorizWalls[20] = new Rectangle(31,407,34,4);					// horizontal bottom row 5 horizontal
		   botHorizWalls[21] = new Rectangle(122,407,64,4);					// horizontal bottom row 5 horizontal
		   botHorizWalls[22] = new Rectangle(273,407,65,4);					// horizontal bottom row 5 horizontal
		   botHorizWalls[23] = new Rectangle(364,407,125,4);				// horizontal bottom row 5 horizontal	
		   botHorizWalls[24] = new Rectangle(516,407,34,4);					// horizontal bottom row 5 horizontal	
		   botHorizWalls[25] = new Rectangle(151,434,35,4);					// horizontal bottom row 6 horizontal
		   botHorizWalls[26] = new Rectangle(304,434,64,4);					// horizontal bottom row 6 horizontal	
		   botHorizWalls[27] = new Rectangle(456,434,94,4);					// horizontal bottom row 6 horizontal
		   botHorizWalls[28] = new Rectangle(0,461,34,4);					// horizontal bottom row 7 horizontal	
		   botHorizWalls[29] = new Rectangle(122,461,154,4);				// horizontal bottom row 7 horizontal
		   botHorizWalls[30] = new Rectangle(333,461,34,4);					// horizontal bottom row 7 horizontal	
		   botHorizWalls[31] = new Rectangle(394,461,124,4);				// horizontal bottom row 7 horizontal
		   botHorizWalls[32] = new Rectangle(31,489,34,4);					// horizontal bottom row 8 horizontal
		   botHorizWalls[33] = new Rectangle(182,489,155,4);				// horizontal bottom row 8 horizontal
		   botHorizWalls[34] = new Rectangle(364,489,34,4);					// horizontal bottom row 8 horizontal
		   botHorizWalls[35] = new Rectangle(485,489,94,4);					// horizontal bottom row 8 horizontal	
		   botHorizWalls[36] = new Rectangle(61,516,64,4);					// horizontal bottom row 9 horizontal
		   botHorizWalls[37] = new Rectangle(152,516,33,4);					// horizontal bottom row 9 horizontal
		   botHorizWalls[38] = new Rectangle(215,516,30,4);					// horizontal bottom row 9 horizontal
		   botHorizWalls[39] = new Rectangle(334,516,64,4);					// horizontal bottom row 9 horizontal
		   botHorizWalls[40] = new Rectangle(455,516,34,4);					// horizontal bottom row 9 horizontal
		   botHorizWalls[41] = new Rectangle(548,516,64,4);					// horizontal bottom row 9 horizontal  
	   }
   
// closing attributes to close correctly   
   private void closing() {
	   MainScreen ms = new MainScreen();
	   ms.getMainStage().setOnCloseRequest(new EventHandler<WindowEvent>() {
		    @Override 
		    public void handle(WindowEvent t) {
		    	Platform.exit();
		    	System.exit(0);
		    }
	   });
   }
   
// used to change panes   
   public Pane getMazeOnePane(){
      return mazeOnePane;
   }
}