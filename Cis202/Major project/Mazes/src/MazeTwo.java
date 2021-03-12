// **********************************************************************************
// Title: Mazes
// Author: Cody Murrer
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: MazeTwo.java
// Description: The second and intermediate level of the three mazes
// **********************************************************************************
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.Scene;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

public class MazeTwo{

private StackPane mazeTwoPane;

   public static void main(String[] args){
      new MazeTwo();
   }
   
   public MazeTwo(){
      mazeTwoPane = new StackPane();
   }
   
   public StackPane getMazeTwoPane(){
      return mazeTwoPane;
   }
   
}