import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class HowToPlay{

Label lblTitle = new Label();

Button btnReturn = new Button();

private StackPane howTo;
   
   public static void main(String[] args){
      new HowToPlay();
   }
   
   public HowToPlay(){
        howTo = new StackPane();
        
        lblTitle.setText("How To Play");
  
          btnReturn.setText("Return");
        
        
        howTo.getChildren().add(lblTitle);
               howTo.getChildren().add(btnReturn);
        
   }
   
   public StackPane getHowToPane(){
      return howTo; 
   }
  
}