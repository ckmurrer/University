// packages for javafx attributes to be ran 
import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Main extends Application{

Label lblTitle = new Label();
Button btnPlay = new Button();
Button btnExit = new Button();
Button btnHowTo = new Button();
 
   public static void main(String[] args){
      launch(args);
   }
   
    @Override
    public void start(Stage mainStage) {
        mainStage.setTitle("Chess");
        
        lblTitle.setText("Chess");
 
// sets text and creates ActionEvent for the button that directs to the choose screen before the game starts     
        btnPlay.setText("Play Game");  
        btnPlay.setOnAction(new EventHandler<ActionEvent>() {
 
            @Override
            public void handle(ActionEvent event) {
                System.out.println("Click");
            }
        });

// sets text and creates ActionEvent to direct the user to the rules and info tab   
        btnHowTo.setText("How to Play");
        btnHowTo.setOnAction(new EventHandler<ActionEvent>() {
 
            @Override
            public void handle(ActionEvent event) {
                System.out.println("Click");
            }
        });
        
//sets text and creates ActionEvent for the exit button to terminate the program
        btnExit.setText("Exit");
        btnExit.setOnAction(new EventHandler<ActionEvent>() {
 
            @Override
            public void handle(ActionEvent event) {
                Platform.exit();
            }
        });
        
// creates container where gui objects are added to      
        StackPane root = new StackPane();
        root.getChildren().add(lblTitle);
        root.getChildren().add(btnPlay);
        root.getChildren().add(btnHowTo);
        root.getChildren().add(btnExit);

// sets the placement for the gui objects         
        lblTitle.setTranslateY(-225);
        btnPlay.setTranslateY(-60);
        btnExit.setTranslateY(60);

// creates the stage        
        mainStage.setScene(new Scene(root, 500, 500));
        mainStage.show();
    }
}