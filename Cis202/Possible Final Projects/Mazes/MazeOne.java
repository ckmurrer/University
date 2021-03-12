// Maze one

// https://xefer.com/maze-generator
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.shape.Rectangle;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import java.util.Random;

public class MazeOne{

Label player = new Label();
Label testWall = new Label();

Rectangle ptest = new Rectangle(10,10,10,10);


private StackPane mazeOnePane;

   public static void main(String[] args){
      new MazeOne();
   }
   
   public MazeOne(){
   
      mazeOnePane = new StackPane();

      testWall.setPrefWidth(15);
      testWall.setPrefHeight(15);
      testWall.setTranslateY(15);
      testWall.setTranslateX(15); 
      
      testWall.setStyle("-fx-Background-color:#debFFF;");
      
      double hh = ptest.getX();
      System.out.println(hh);
  /*    
      ptest.setX(100);
      ptest.setY(100);
      ptest.setWidth(15);
      ptest.setHeight(15);
      ptest.setFocusTraversable(true);*/
      //ptest.setStyle("-fx-Background-color:#deb887;");
      
/*       
      player.setPrefWidth(15);
      player.setPrefHeight(15);
      player.setTranslateY(0);
      player.setTranslateX(0);
      player.setFocusTraversable(true);
      
      player.setStyle("-fx-Background-color:#deb887;");
  */  
      
      mazeOnePane.getChildren().add(testWall);
      mazeOnePane.getChildren().add(ptest);
    //  mazeOnePane.getChildren().add(player);

      
      Movement();
   }
   
   public void Movement() {
 
      ptest.setOnKeyPressed(e -> {  
    
         KeyCode kp = e.getCode();       
         switch (kp) {
      
            case DOWN:
               double pcd = ptest.getY();

               if(ptest.getY() <= 290){ 
                  System.out.println("Down: "+pcd);
                  ptest.setY(ptest.getY() + 5);         
               }
            break;
         
            case UP: 
               double pcu = ptest.getY();
            
               if(ptest.getY() >= -290){ 
                  System.out.println("Up: "+pcu);
                  ptest.setY(ptest.getY() - 5);        
               }
               
            break;
         
            case LEFT:
               double pcl = ptest.getX();
            
               if(ptest.getX() >= -290){          
                  System.out.println("Left: "+pcl);
                  ptest.setX(ptest.getX() - 5);    
               } 
                       
            break;
     
            case RIGHT:  
               double pcr = ptest.getX();
            
               if(ptest.getX() <= 290){ 
                  System.out.println("Right: "+pcr);
                  ptest.setX(ptest.getX() + 5);               
               }
            break;
         }
      }); 
   }   
 /*  
   public void CollisionDetection(){
   
      double colP = player.getTranslateX();
      double colW = testWall.getTranslateX()-15;
      double colPT = player.getTranslateY();
      double colWT = testWall.getTranslateY()-15;

      System.out.println("colW x: "+ colW);
   
      if( colP == colW){
         System.out.println("Collision");
      }
   }
*/   
   public StackPane getMazeOnePane(){
      return mazeOnePane;
   }
}