// Maze Two
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