// **********************************************************************************
// Title: Mazes
// Author: Cody Murrer
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: MazeOne.java
// Description: The first and easiest maze of three different mazes 
// **********************************************************************************
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.input.KeyCode;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class MazeOne{

// booleans to control collisions 
Boolean left = false;
Boolean right = false;
Boolean up = false; 
Boolean down = false;

// boolean to start the clock
Boolean clockStart = false;

// return button
Button btnReturn = new Button();

// labels for background image and timer
Label lblPlaceHolder = new Label();
Label lblTimerBorder = new Label();
Label lblTimerDesc = new Label("Time Spent");
Label lblPlayerTimer = new Label("00:00:00");

// rectanlge for player character and the start and stop locations
Rectangle rectPlayer = new Rectangle();
Rectangle rectStart = new Rectangle();
Rectangle rectEnd = new Rectangle();

// array list of recatngles for the walls on the maze
Rectangle[] vertWalls = new Rectangle[30];
Rectangle[] horizWalls = new Rectangle[20];

private Pane mazeOnePane;

   public static void main(String[] args){
      new MazeOne();
   }
   
   public MazeOne(){
	   
      mazeOnePane = new Pane();
      startPos();
      walls();
      
      lblPlaceHolder.setPrefWidth(610);
      lblPlaceHolder.setPrefHeight(546);
      lblPlaceHolder.setStyle("-fx-border-color: cyan;");
      lblPlaceHolder.setTranslateX(0);
      lblPlaceHolder.setTranslateY(0);

// placeholder image to put walls over      
      try{          
          FileInputStream MazeOne = new FileInputStream("images/maze_one_placement_test_one.png");        
          Image mOne = new Image(MazeOne);    
          ImageView imageView = new ImageView(mOne);   
          lblPlaceHolder.setGraphic(imageView);                    
          
       }catch(FileNotFoundException UhOh) { 
          System.out.println(UhOh.getMessage());
       } 
       
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
      
      lblPlayerTimer.setPrefWidth(100);
      lblPlayerTimer.setPrefHeight(50);
      lblPlayerTimer.setFont(new Font("Arial", 20));
      lblPlayerTimer.setTranslateX(20);
      lblPlayerTimer.setTranslateY(565);
    
      rectPlayer.setWidth(15);
      rectPlayer.setHeight(15);
      rectPlayer.setY(520);
      rectPlayer.setX(310);
      rectPlayer.setFocusTraversable(true);  
      rectPlayer.setFill(Color.FUCHSIA);

// adds nodes to the pane      
      mazeOnePane.getChildren().addAll(lblPlayerTimer,lblTimerDesc,lblTimerBorder,lblPlaceHolder,rectStart);
      mazeOnePane.getChildren().add(rectPlayer);

// adds the walls array to the pane      
      for(int i = 0; i< vertWalls.length; i++) {
    	  
    	  vertWalls[i].setFill(Color.RED);
    	  mazeOnePane.getChildren().add(vertWalls[i]);
      
      }
   	  Movement();
   }

//sets the start postion for the player   
   public void startPos() {
	   
	   rectStart.setWidth(27);
	   rectStart.setHeight(28);
	   rectStart.setY(516);
	   rectStart.setX(307);
	  rectStart.setFill(Color.LIGHTGREEN);
   }

// method for the timer   
   public void clock() {
	      
   }

// method for when the user has reached the end   
   public void endPos() {
	   	   
   }
   
   public void walls() {
// vert walls left to right	   
	   vertWalls[0] = new Rectangle(0,0,4,546);			// outer wall left down
	   vertWalls[1] = new Rectangle(0,544,337,4); 		// outer wall bottom left to start
	   vertWalls[2] = new Rectangle(0,0,277,4);  		// outer wall top left to end 
	   vertWalls[3] = new Rectangle(304,0,307,4);  		// outer wall end to top right
	   vertWalls[4] = new Rectangle(606,0,4,546);  		// outer wall right down
	   vertWalls[5] = new Rectangle(334,544,280,4); 	// outer wall start to bottom right 
	   vertWalls[6] = new Rectangle(31,28,4,112);		// vertical row 1 column 1
	   vertWalls[7] = new Rectangle(31,163,4,113);		// vertical row 2 column 1
	   vertWalls[8] = new Rectangle(31,326,4,112);		// vertical row 3 column 1
	   vertWalls[9] = new Rectangle(31,489,4,31);		// vertical row 4 column 1
	   vertWalls[10] = new Rectangle(61,28,4,30);		// vertical row 1 column 2
	   vertWalls[11] = new Rectangle(61,109,4,31);		// vertical row 2 column 2
	   vertWalls[12] = new Rectangle(61,190,4,58);		// vertical row 3 column 2
	   vertWalls[13] = new Rectangle(61,299,4,58);		// vertical row 4 column 2
	   vertWalls[14] = new Rectangle(61,407,4,86);		// vertical row 5 column 2
	   vertWalls[15] = new Rectangle(91,27,4,31);		// vertical row 1 column 3
	   vertWalls[16] = new Rectangle(91,109,4,85);		// vertical row 2 column 3
	   vertWalls[17] = new Rectangle(91,381,4,139);		// vertical row 3 column 3
	   vertWalls[18] = new Rectangle(122,0,4,31);		// vertical row 1 column 4
	   vertWalls[19] = new Rectangle(122,55,4,85);		// vertical row 2 column 4
	   vertWalls[20] = new Rectangle(122,190,4,58);		// vertical row 3 column 4
	   vertWalls[21] = new Rectangle(122,272,4,31);		// vertical row 4 column 4
	   vertWalls[22] = new Rectangle(122,381,4,111);	// vertical row 5 column 4
	   vertWalls[23] = new Rectangle(122,516,4,28);		// vertical row 6 column 4
	   vertWalls[24] = new Rectangle(152,82,4,31);		// vertical row 1 column 5
	   vertWalls[25] = new Rectangle(152,136,4,30);		// vertical row 2 column 5
	   vertWalls[26] = new Rectangle(152,299,4,31);		// vertical row 3 column 5
	   vertWalls[27] = new Rectangle(152,354,4,31);		// vertical row 4 column 5
	   vertWalls[28] = new Rectangle(152,489,4,31);		// vertical row 5 column 5
	   vertWalls[29] = new Rectangle(182,28,4,30);		// vertical row 1 column 6
	   
   }
   
   public void Movement() {
// key press that activates a switch case to move the player within the bounds of the play area   
	   rectPlayer.setOnKeyPressed(e -> {  
		   CollisionDetection();
		   
		   KeyCode kp = e.getCode();       
	       switch (kp) {      
	          case S:
	        	  if(rectPlayer.getY() <= 525){ 	        		 
	        		 rectPlayer.setY(rectPlayer.getY() + 5);  
	        		 
	        		 down = true;
	        		 up = false;
	        		 left = false;
	        		 right = false;
	        	  } 
	          break;
	         
	          case W: 	        	  	            	
	        	  if(rectPlayer.getY() >= 5){ 	        		  
	        		  rectPlayer.setY(rectPlayer.getY() - 5); 
	        		  
	        		  up = true;
	        		  down = false;
	        		  left = false;
	        		  right= false;
	        	  } 
	          break;
	         
	          case A:
	        	  if(rectPlayer.getX() >= 5){ 
	        		  rectPlayer.setX(rectPlayer.getX() - 5);    
	        		  
	        		  left = true;
	        		  right = false;
	        		  up = false;
	        		  down = false;
	        	  }
	          break;
	     
	          case D: 
	        	  if(rectPlayer.getX() <= 590){   
	        		  rectPlayer.setX(rectPlayer.getX() + 5);        
	        		  
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

// method of detecting when and where the players rectangle hits a wall   
   public void CollisionDetection(){
	for(int i = 0; i < vertWalls.length; i++) {   
	   if(up == true) {
		   if(rectPlayer.getBoundsInParent().intersects(vertWalls[i].getBoundsInParent())) {
			   rectPlayer.setY(rectPlayer.getY()+5);
			   double pcu =rectPlayer.getY();
// prints y value when colliding on the bottom of the wall			   
			   System.out.println("Up: "+pcu);
			   System.out.println("Bottom of wall"); 
		   }
	   }else if(down == true) {
		   if(rectPlayer.getBoundsInParent().intersects(vertWalls[i].getBoundsInParent())) {
			   rectPlayer.setY(rectPlayer.getY()-5);
			   double pcd = rectPlayer.getY();
// prints y value when colliding on top of the wall			   
			   System.out.println("Down: "+pcd);
			   System.out.println("Top of wall"); 
		   }
	   }else if(left == true) {
		   if(rectPlayer.getBoundsInParent().intersects(vertWalls[i].getBoundsInParent())) {
			   rectPlayer.setX(rectPlayer.getX()+5);
			   double pcl = rectPlayer.getX();
// prints x value when colliding on the left side of the wall			   
			   System.out.println("Left: "+pcl);
			   System.out.println("Right of wall");
		   }
	   }else if(right == true) {
		   if(rectPlayer.getBoundsInParent().intersects(vertWalls[i].getBoundsInParent())) {
			   rectPlayer.setX(rectPlayer.getX()-5);
// prints X value when colliding on the left side of the wall			   
			   double pcr = rectPlayer.getX();
			   System.out.println("Right: "+pcr);
			   System.out.println("Left of wall");
		   }
	   }
	}
// if statement to call the timer class to start when the player is no longer colliding with the starting spot   
	   if(clockStart == false) {
		   if(!(rectPlayer.getBoundsInParent().intersects(rectStart.getBoundsInParent()))) {
			   clockStart = true;
			   System.out.println("clock is ticking");
		   }
	   }
   }
   
   public Pane getMazeOnePane(){
      return mazeOnePane;
   }
}