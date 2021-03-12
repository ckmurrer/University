// **********************************************************************************
// Title: Mazes
// Author: Cody Murrer
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: MazeThree.java
// Description: The third an hardest maze of the three
// **********************************************************************************
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

public class MazeThree{

private StackPane mazeThreePane;

   public static void main(String[] args){   
      new MazeThree();
   }
   
   public MazeThree(){
      mazeThreePane = new StackPane();
   }
   
   public StackPane getMazeThreePane(){
      return mazeThreePane;
   }
}