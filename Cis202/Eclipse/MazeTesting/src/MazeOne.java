// Maze one

// https://xefer.com/maze-generator
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

public class MazeOne{

Label player = new Label();
StackPane mazeOnePane;


   public static void main(String[] args){
      new MazeOne();
   }
   
   public MazeOne(){
   
      mazeOnePane = new StackPane();
      
      
      player.setPrefWidth(15);
      player.setPrefHeight(15);
      player.setTranslateY(0);
      player.setTranslateX(0);
      player.setFocusTraversable(true);
      
      player.setStyle("-fx-Background-color:#deb887;");
      
      mazeOnePane.getChildren().add(player);
       Movement();
   }
   
 public void Movement() {
 
   player.setOnKeyPressed(e -> {          
      switch (e.getCode()) {
         case DOWN: 
            player.setTranslateY(player.getTranslateY() + 10);
         break;
        case UP:   break;
        case LEFT:  break;
        case RIGHT:  break;
      }
  });

// get keycode 

// switch case to switch between keys

// method of += or -= per case

// possible use of timers  

   
}
   
   
   public void CollisionDetection(){
   
   }
   
   public StackPane getMazeOnePane(){
      return mazeOnePane;
   }
}