// multiplayer menu

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class MultiplayerMenu{
   
private StackPane multiMenu;
   
   public static void main(String[] args){
      new MultiplayerMenu();
   }
   
   public MultiplayerMenu(){
      
      multiMenu = new StackPane();
   }
   
   public StackPane getMultiMenu(){
      return multiMenu;
   }
}