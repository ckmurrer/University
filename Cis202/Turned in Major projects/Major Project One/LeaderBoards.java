// **********************************************************************************
// Title: Mazes
// Author: Cody Murrer
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: LeaderBoards.java
// Description: An arcade style leaderboard listed to 10 with the top 10 times on each maze with the 3 letter initials
// **********************************************************************************
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;

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
      
	   leaderBoard = new StackPane();
   }
   
   public StackPane getLeaderboards(){
      return leaderBoard;
   }
}