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
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class MazeSelect{

// creates labels
Label lblTitle = new Label("Maze Selection");
Label lblMazeOneIMG = new Label();
Label lblMazeTwoIMG = new Label();
Label lblMazeThreeIMG = new Label();

// creates buttons
Button btnMazeOne = new Button("Maze One");
Button btnMazeTwo = new Button("Maze Two");
Button btnMazeThree = new Button("Maze Three");
Button btnBack = new Button("Return"); 

/*
radio button for an auto play stacking maps ontop of eachother to start the next map almost right away once completion of the inital one
RadioButton rdbAuto = new RadioButton();

*/
private StackPane select;

   public static void main(String[] args){
      new MazeSelect();
   }
   
   public MazeSelect(){
      
      select = new StackPane();
      
      lblTitle.setPrefWidth(90);
      lblTitle.setPrefHeight(50);
      lblTitle.setTranslateX(0);
      lblTitle.setTranslateY(-250);
      
      lblMazeOneIMG.setPrefWidth(200);
      lblMazeOneIMG.setPrefHeight(200);
      lblMazeOneIMG.setTranslateX(-200);
      lblMazeOneIMG.setTranslateY(-100);

// sets thumbnail image for maze 1      
       try{          
         FileInputStream MazeOne = new FileInputStream("images/maze_1_thumb.png");        
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

// sets thumbnail image for maze 2      
       try{          
         FileInputStream MazeTwo = new FileInputStream("images/maze_2_thumb.png");        
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

// sets thumbnail image for maze 3       
       try{          
         FileInputStream MazeThree = new FileInputStream("images/maze_3_thumb.png");        
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

// button to launch you into maze one      
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

// button to launch you into maze two      
      btnMazeTwo.setOnAction(new EventHandler<ActionEvent>() {       
         @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnMazeTwo){              
               MazeTwo mTwo = new MazeTwo();
               
               MainScreen main = new MainScreen();
               main.getMainStage().getScene().setRoot(mTwo.getMazeTwoPane());
            }
         }
      });   
            
      btnMazeThree.setPrefWidth(90);
      btnMazeThree.setPrefHeight(30);
      btnMazeThree.setTranslateX(250);
      btnMazeThree.setTranslateY(50);

// button to launch you into maze three       
      btnMazeThree.setOnAction(new EventHandler<ActionEvent>() {       
         @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnMazeThree){              
               MazeThree mThree = new MazeThree();
               
               MainScreen main = new MainScreen();
               main.getMainStage().getScene().setRoot(mThree.getMazeThreePane());
            }
         }
      });     
          
      btnBack.setPrefWidth(90);
      btnBack.setPrefHeight(30);
      btnBack.setTranslateX(25);
      btnBack.setTranslateY(120);

// button to return to main menu      
       btnBack.setOnAction(new EventHandler<ActionEvent>() {       
         @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnBack){              
               MainScreen main = new MainScreen();
               main.getMainStage().getScene().setRoot(main.getMenuScreen());
            }
         }
      });   
 
// adds nodes to the pane            
      select.getChildren().addAll(lblTitle, lblMazeOneIMG, lblMazeTwoIMG, lblMazeThreeIMG, btnMazeOne, btnMazeTwo, btnMazeThree, btnBack);
   }

// used to acess the pane from another class to switch the pane on the scene   
   public StackPane getSelect(){
      return select; 
   } 
}