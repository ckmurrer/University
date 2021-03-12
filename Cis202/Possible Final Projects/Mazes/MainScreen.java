// Game Idea for Final Project Two
// unironic_cringe
// The player works their way through mulitple mazes in a single player aspect
// The player races against a clock to try and beat the time as the other player playing the same maze is trying to do the same (Cont)
// when both players are done a popup box will tell both players who had the fastest time and if they would like to play again

// **********************************************************************************
// Title: Mazes
// Author: Cody Murrer
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: MainScreen.java
// Description: the main menu screen used for initial navigation between the scenes
// **********************************************************************************

// Main menu screen

import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class MainScreen extends Application{

private StackPane MenuScreen;     
   
Label lblTitle = new Label();

Button btnSingle = new Button();
Button btnMulti = new Button();
Button btnHowTo = new Button();
Button btnExit = new Button();

private static Stage mStage;   
   
   public static void main(String[] args){
      launch(args);
   }
   
   public MainScreen(){
   
      MenuScreen = new StackPane();
   
// Title label      
      lblTitle.setText("Welcom To Fun With Mazes");
      lblTitle.setPrefWidth(50);
      lblTitle.setPrefHeight(50);
      lblTitle.setTranslateY(50);
      lblTitle.setTranslateX(50);

// Single-Player button      
      btnSingle.setText("Single-Player");
      btnSingle.setPrefWidth(80);
      btnSingle.setPrefHeight(25);
      btnSingle.setTranslateY(40);
      btnSingle.setTranslateX(50);

// sets EventHandler to button         
      btnSingle.setOnAction(new EventHandler<ActionEvent>() {       
         @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnSingle){   
               MazeSelect ms = new MazeSelect();                  
               mStage.getScene().setRoot(ms.getSelect());
               mStage.centerOnScreen();
            }
         }
      });      

// Multiplayer button      
      btnMulti.setText("Multiplayer");
      btnMulti.setPrefWidth(80);
      btnMulti.setPrefHeight(25);
      btnMulti.setTranslateY(90);
      btnMulti.setTranslateX(50);
 
// sets EventHandler to button         
      btnMulti.setOnAction(new EventHandler<ActionEvent>() {       
         @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnMulti){
               MenuScreen.setVisible(false);               
               MultiplayerMenu mpm = new MultiplayerMenu();                  
               mStage.getScene().setRoot(mpm.getMultiMenu());
               mStage.centerOnScreen();
            }
         }
      });

// How To Play button      
      btnHowTo.setText("How To Play");
      btnHowTo.setPrefWidth(80);
      btnHowTo.setPrefHeight(25);
      btnHowTo.setTranslateY(120);
      btnHowTo.setTranslateX(50);

// sets EventHandler to button      
      btnHowTo.setOnAction(new EventHandler<ActionEvent>() {       
         @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnHowTo){
               MenuScreen.setVisible(false);               
               HowToPlay htp = new HowToPlay();                  
               mStage.getScene().setRoot(htp.getHowToPane());
               mStage.centerOnScreen(); 
            }
         }
      });

// Exit button      
      btnExit.setText("Exit");
      btnExit.setPrefWidth(80);
      btnExit.setPrefHeight(25);
      btnExit.setTranslateY(170);
      btnExit.setTranslateX(50);

// sets EventHandler to button         
      btnExit.setOnAction(new EventHandler<ActionEvent>() {       
         @Override
         public void handle(ActionEvent event) {
            Platform.exit();
            System.exit(0);
         }
      });

// adds nodes to the MenuScreen 
      getMenuScreen().getChildren().addAll(lblTitle, btnSingle, btnMulti, btnHowTo, btnExit);
   }

// start method   
   @Override
   public void start(Stage mainStage){
   
      new MainScreen();
      mStage = mainStage;
      
// title and favicon of stage   
      mStage.setTitle("Fun With Mazes");
      try{          
         FileInputStream Favicon = new FileInputStream("images/M.gif");        
         Image favi = new Image(Favicon);                       
         mStage.getIcons().add(favi);
      }catch(FileNotFoundException UhOh) { 
         System.out.println(UhOh.getMessage());
      }  

 // creates the stage and adds the main menu to it    
      mStage.setScene(new Scene(MenuScreen, 600, 600));
      mStage.setResizable(false);
      mStage.show();
   } 

// used to call stage within different classes   
     public Stage getMainStage(){
      return mStage;
   }

// used to call the menu scene for return buttons   
   public StackPane getMenuScreen(){
      return MenuScreen;
   }
} // public class