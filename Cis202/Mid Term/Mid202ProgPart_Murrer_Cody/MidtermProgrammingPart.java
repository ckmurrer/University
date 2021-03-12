// *******************************************************
// * CIS 202 Midterm Exam - Programming Part
// * NAME:  Cody Murrer 1 point
// * FILE:  MidtermProgrammingPart.java  1 point
// *******************************************************
// Directions:  Replace the ??? through out the code with
//              the appropriate Java code. (15 total points)

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;
// Place the correct class in the place of ??? on the next three lines (3 points)
import javafx.stage.Stage;
import javafx.stage.FileChooser;
import javafx.stage.FileChooser.ExtensionFilter;
// Import the File class to replace the ??? on the next line (2 points)
import java.io.File;

// Create the appropriate class definition with inheritance to replace the ??? on the next line. (3 points)
public class MidtermProgrammingPart extends Application {
  @Override // Override the start method in the Application class
  public void start(Stage primaryStage) {
    String filename=null;
    // Create and instantiate the fileChooser object (2 points)
    FileChooser fileChooser = new FileChooser();
    fileChooser.setTitle("Open Resource File");
    fileChooser.getExtensionFilters().addAll(
          new ExtensionFilter("Text Files", "*.txt"));
    
    // Use the fileChooser object to show a dialog box to get the selected File object. (3 points)
    File selectedFile = fileChooser.showOpenDialog(null);
    if (selectedFile != null) {
       filename = selectedFile.getName();
    }
    PaintersEngine pe = new PaintersEngine();
    
    if (filename != null) {
       pe.loadGobList(filename);
       primaryStage.setTitle("Painter's Engine"); // Set the stage title
       pe.displayStage(primaryStage);
    }
    else
       System.exit(0);
  }
  
  /**
   * The main method is only needed for the IDE with limited
   * JavaFX support. Not needed for running from the command line.
   */
  public static void main(String[] args) {
    launch(args);
  }
}
