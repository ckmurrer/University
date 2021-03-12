import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import java.io.IOException;

public class GameScreen extends Application{

private Image[][] playerSprite;

Label player = new Label();

   public static void main(String[] args){
      launch(args);
   }
   
    @Override
   public void start(Stage mainStage){
   
      StackPane homeScreen = new StackPane();
      mainStage.setTitle("Project Testing");
      
      playerMovement();

      homeScreen.getChildren().add(player);
      
// creates the stage        
      mainStage.setScene(new Scene(homeScreen, 900, 500));
      mainStage.setResizable(false);
      mainStage.show();
   }
   
   public void playerMovement(){
      
      player.setPrefHeight(100);
      player.setPrefWidth(100);
      
      player.setTranslateY(200);
      player.setTranslateX(-400);
      
      player.setStyle("-fx-Background-color:#deb887;"); 
      
      try{
	      SpriteLoader sSheet = new SpriteLoader("/images/spriteM1Walk.png");
         
         Image sImage = new Image(sSheet.getSprite(3, 0, player.getWidth(.0), player.getHeight(.0)));
         ImageView sView = new ImageView(sImage);
         
	      player.setGraphic(sView);
                  
	      playerSprite = sSheet.getAllSprites(player.getWidth(.0), player.getHeight(.0));
         
	   }catch(IOException e1){
	      e1.printStackTrace();
      } 
   }
}