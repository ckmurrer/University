// How to play screen

import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.Scene;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class HowToPlay{

Button btnReturn = new Button();
private StackPane howTo;

   public static void main(String[] args){
      new HowToPlay();
   }
   
   public HowToPlay(){
      
      btnReturn.setText("Return");
      btnReturn.setPrefWidth(80);
      btnReturn.setPrefHeight(25);
      btnReturn.setTranslateY(0);
      btnReturn.setTranslateX(0);
      
      btnReturn.setOnAction(new EventHandler<ActionEvent>() {       
         @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnReturn){              
               MainScreen main = new MainScreen();
               main.getMainStage().getScene().setRoot(main.getMenuScreen());
            }
         }
      });     
      
      howTo = new StackPane();
      
      howTo.getChildren().add(btnReturn);
   }
   
   public StackPane getHowToPane(){
      return howTo; 
   }  
}