// maze three
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.Scene;
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