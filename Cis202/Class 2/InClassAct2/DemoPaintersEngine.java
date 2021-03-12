// **********************************************************************************
// Title: Painters Engine
// Author: Cody Murrer
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: DemoPaintersEngine.java
// Description: Proudeces shapes and colors on screen
// **********************************************************************************

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.stage.FileChooser;
import javafx.stage.FileChooser.ExtensionFilter;
import java.io.File;

public class DemoPaintersEngine extends Application {
  @Override // Override the start method in the Application class
  public void start(Stage primaryStage) {
    String filename=null;
    FileChooser fileChooser = new FileChooser();
    fileChooser.setTitle("Open Resource File");
    fileChooser.getExtensionFilters().addAll(
          new ExtensionFilter("Text Files", "*.txt"));
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
