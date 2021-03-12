// **********************************************************************************
// Title: Mazes
// Author: Cody Murrer
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: MazeSelect.java
// Description: The selection screen for the choice on which maze you wish to play
// **********************************************************************************
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.WindowEvent;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class MazeSelect{

Label lblTitle = new Label("Maze Selection");
Label lblMazeOneIMG = new Label();
Label lblMazeTwoIMG = new Label();
Label lblMazeThreeIMG = new Label();

Button btnMazeOne = new Button("Maze One");
Button btnMazeTwo = new Button("Maze Two");
Button btnMazeThree = new Button("Maze Three");
Button btnBack = new Button("Return"); 

// possibly used for a stack/queue
RadioButton rdbAuto = new RadioButton();

private StackPane select;

   public static void main(String[] args){
      new MazeSelect();
   }
   
   public MazeSelect(){
      closing();
      select = new StackPane();
      
      lblTitle.setPrefWidth(90);
      lblTitle.setPrefHeight(50);
      lblTitle.setTranslateX(0);
      lblTitle.setTranslateY(-250);
      
      lblMazeOneIMG.setPrefWidth(200);
      lblMazeOneIMG.setPrefHeight(200);
      lblMazeOneIMG.setTranslateX(-200);
      lblMazeOneIMG.setTranslateY(-100);
      
       try{          
         FileInputStream MazeOne = new FileInputStream("src/images/maze_1_thumb.png");        
         Image mOne = new Image(MazeOne);    
         ImageView imageView = new ImageView(mOne);   
         lblMazeOneIMG.setGraphic(imageView);                    
         
      }catch(FileNotFoundException UhOh) { 
         System.out.println(UhOh.getMessage());
      } 
      
      
      lblMazeTwoIMG.setPrefWidth(200);
      lblMazeTwoIMG.setPrefHeight(200);
      lblMazeTwoIMG.setTranslateX(25);
      lblMazeTwoIMG.setTranslateY(-100);
      
       try{          
         FileInputStream MazeTwo = new FileInputStream("src/images/maze_2_thumb.png");        
         Image mTwo = new Image(MazeTwo);       
         ImageView imageView = new ImageView(mTwo);   
         lblMazeTwoIMG.setGraphic(imageView);                 

      }catch(FileNotFoundException UhOh) { 
         System.out.println(UhOh.getMessage());
      } 
      
      lblMazeThreeIMG.setPrefWidth(200);
      lblMazeThreeIMG.setPrefHeight(200);
      lblMazeThreeIMG.setTranslateX(250);
      lblMazeThreeIMG.setTranslateY(-100);
      
       try{          
         FileInputStream MazeThree = new FileInputStream("src/images/maze_3_thumb.png");        
         Image mThree = new Image(MazeThree);  
         ImageView imageView = new ImageView(mThree);   
         lblMazeThreeIMG.setGraphic(imageView);

      }catch(FileNotFoundException UhOh) { 
         System.out.println(UhOh.getMessage());
      } 
      
      btnMazeOne.setPrefWidth(90);
      btnMazeOne.setPrefHeight(30);
      btnMazeOne.setTranslateX(-200);
      btnMazeOne.setTranslateY(50);
      
      btnMazeOne.setOnAction(new EventHandler<ActionEvent>() {       
         @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnMazeOne){              
               MazeOne mOne = new MazeOne();
               MainScreen main = new MainScreen();
               main.getMainStage().getScene().setRoot(mOne.getMazeOnePane());
            }
         }
      });   
      
      btnMazeTwo.setPrefWidth(90);
      btnMazeTwo.setPrefHeight(30);
      btnMazeTwo.setTranslateX(25);
      btnMazeTwo.setTranslateY(50);
      
      btnMazeTwo.setOnAction(new EventHandler<ActionEvent>() {       
         @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnMazeTwo){              
            	WIP.error();
            }
         }
      });   
            
      btnMazeThree.setPrefWidth(90);
      btnMazeThree.setPrefHeight(30);
      btnMazeThree.setTranslateX(250);
      btnMazeThree.setTranslateY(50);
      
      btnMazeThree.setOnAction(new EventHandler<ActionEvent>() {       
         @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnMazeThree){              
            	WIP.error();
            }
         }
      });     
          
      btnBack.setPrefWidth(90);
      btnBack.setPrefHeight(30);
      btnBack.setTranslateX(25);
      btnBack.setTranslateY(120);
      
       btnBack.setOnAction(new EventHandler<ActionEvent>() {       
         @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnBack){              
               MainScreen main = new MainScreen();
               main.getMainStage().getScene().setRoot(main.getMenuScreen());
            }
         }
      });   
            
      select.getChildren().addAll(lblTitle, lblMazeOneIMG, lblMazeTwoIMG, lblMazeThreeIMG, btnMazeOne, btnMazeTwo, btnMazeThree, btnBack);
   }
   
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
   public StackPane getSelect(){
      return select; 
   } 
}