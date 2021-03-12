// imports needed javafx packages
import javafx.application.*;
import javafx.event.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.stage.*;
import javafx.scene.image.*;
import javafx.geometry.*;

public class CookingManual extends Application implements EventHandler<ActionEvent>{
   Button ex;
   Button ent;
   Label header;
   Label textHeader;
   TextField search;
   
   public static void main(String[] args){
// launches the program   
      launch(args);   
   }
   
   @Override
   public void start(Stage primaryStage) throws Exception{
      primaryStage.setTitle("Cooking Manual");

// sets controls      
      search = new TextField();
      
      ex = new Button();
      ex.setText("Exit");
      ex.setOnAction(this);
      
      ent = new Button();
      ent.setText("New Entry");
      ent.setOnAction(this);
      
// sets headers      
      textHeader = new Label();
      textHeader.setText("Search Library");
      
      header = new Label();
      header.setText("Welcome to the cooking manual");
      
// adds children to pane      
      FlowPane root = new FlowPane();
      root.getChildren().add(search);
      root.getChildren().add(ent);
      root.getChildren().add(ex); 
      root.getChildren().add(textHeader);
      root.getChildren().add(header);     

// creates scene and sets favicon   
      Scene scene = new Scene(root, 500, 500);
      primaryStage.getIcons().add(new Image(CookingManual.class.getResourceAsStream("/images/cookPot.jpg")));
      primaryStage.setScene(scene);
      primaryStage.show();

   }
   
// sets rules for when controls are used
      @Override
      public void handle(ActionEvent event){
         if(event.getSource()==ent){
            System.out.println("button press");
         }
         
         if(event.getSource()==ex){
            Platform.exit();
         }
      
     }
}
