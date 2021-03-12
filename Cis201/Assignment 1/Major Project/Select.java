import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Select extends Application{
   
   boolean selection;
   
   Label lblTitle = new Label();
   
   Button btnTwoPlayer = new Button();
   Button btnSinglePlayer = new Button();
   
   Button btnReturn = new Button();
   
   public static void main(String[] args){
   
         launch(args);
   }
   
       public void start(Stage mainStage) {
        mainStage.setTitle("Chess");
        
        btnTwoPlayer.setText("Player vs Player");
        btnTwoPlayer.setOnAction(new EventHandler<ActionEvent>() {
 
            @Override
            public void handle(ActionEvent event) {
                selection = true;
             // goes to board for pvp   
             // uses boolean value to distinguish between pvp pve
            }
        });
       
        btnSinglePlayer.setText("Player vs Computer");
        btnSinglePlayer.setOnAction(new EventHandler<ActionEvent>() {
 
            @Override
            public void handle(ActionEvent event) {
                selection = false;
            // goes to board to pve
            // uses boolean value to distinguish between pve pvp

            }
        });
     
        btnReturn.setText("Back to Main Menu");
        btnReturn.setOnAction(new EventHandler<ActionEvent>() {
 
            @Override
            public void handle(ActionEvent event) {
            // goes back to main    
            }
        });
        
        StackPane root = new StackPane();
        mainStage.setScene(new Scene(root, 500, 500));
        mainStage.show();
    }
}
