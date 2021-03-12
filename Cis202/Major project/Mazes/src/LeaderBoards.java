// **********************************************************************************
// Title: Mazes
// Author: Cody Murrer
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: LeaderBoards.java
// Description: An arcade style leaderboard listed to 10 with the top 10 times on each maze with the 3 letter initials
// **********************************************************************************
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.WindowEvent;

public class LeaderBoards{

Button btnReturn = new Button();
Button btnMOne = new Button();
Button btnMTwo = new Button();
Button btnMThree = new Button();


private StackPane leaderBoard;
   
   public static void main(String[] args){
      new LeaderBoards();
   }
   
   public LeaderBoards(){
	   closing();
	   leaderBoard = new StackPane();
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
   
   public StackPane getLeaderBoards(){
      return leaderBoard;
   }
}