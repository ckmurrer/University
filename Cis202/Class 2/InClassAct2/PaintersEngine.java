

import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Shape;
import javafx.scene.shape.Arc;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.scene.shape.Path;
import javafx.scene.text.Text;
import javafx.scene.shape.Polygon;
import javafx.scene.shape.Polyline;
import javafx.scene.shape.Rectangle;
import javafx.scene.paint.Color;

import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.ButtonType;

import java.util.ArrayList;
import java.util.Optional;
import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;
import java.io.IOException;

public class PaintersEngine {
   // Declare array list of graphical objects
   private ArrayList<Gob> gobList = new ArrayList<Gob>();
   private Stage stage=null;
   private boolean fileRead = false;
   public void loadGobList(String filename) {
      double[] points;
      Color stroke = Color.BLACK;
      Color fill = null;
      try {
         File fileObj = new File(filename);
         String line;
         String tokens[];
         if (fileObj.exists()) {
            gobList.clear();
            Scanner fileIn = new Scanner(fileObj);
            while (fileIn.hasNext()) {
               line = fileIn.nextLine();
               tokens = line.split("\\s");

               // Circle, Ellipse, Line, Polygon, Polyline, Rectangle       
               switch (tokens[0]) {
                  case "Throw":
                     throw new IOException("Arg!");
                  case "Arc":
                     // Arc(double centerX, double centerY, double radiusX, 
                     //     double radiusY, double startAngle, double length)
                     gobList.add(new Gob(new Arc(Double.parseDouble(tokens[1]), 
                                         Double.parseDouble(tokens[2]),
                                         Double.parseDouble(tokens[3]),
                                         Double.parseDouble(tokens[4]), 
                                         Double.parseDouble(tokens[5]),
                                         Double.parseDouble(tokens[6])), fill, stroke));
                     break;
                  case "Circle":
                     gobList.add(new Gob(new Circle(Double.parseDouble(tokens[1]), 
                                         Double.parseDouble(tokens[2]),
                                         Double.parseDouble(tokens[3])), fill, stroke));
                     break;                  
                  case "Ellipse":
                     gobList.add(new Gob(new Ellipse(Double.parseDouble(tokens[1]), 
                                         Double.parseDouble(tokens[2]),
                                         Double.parseDouble(tokens[3]),                                         
                                         Double.parseDouble(tokens[4])), fill, stroke));
                     break;
                  case "Fill":
                     fill = new Color(Double.parseDouble(tokens[1]), 
                                         Double.parseDouble(tokens[2]),
                                         Double.parseDouble(tokens[3]),
                                         Double.parseDouble(tokens[4]));
                     break;
                  case "Line":
                     gobList.add(new Gob(new Line(Double.parseDouble(tokens[1]), 
                                         Double.parseDouble(tokens[2]),
                                         Double.parseDouble(tokens[3]),                                         
                                         Double.parseDouble(tokens[4])), fill, stroke));
                     break;
                  case "Polygon":
                     points = new double[tokens.length-1];
                     for (int i=0; i<points.length; i++) 
                        points[i] = Double.parseDouble(tokens[i+1]);
                     gobList.add(new Gob(new Polygon(points), fill, stroke));
                     break;
                  case "Polyline":
                     points = new double[tokens.length-1];
                     for (int i=0; i<points.length; i++) 
                        points[i] = Double.parseDouble(tokens[i+1]);
                     gobList.add(new Gob(new Polyline(points), fill, stroke));
                     break;
                  case "Rectangle":
                     gobList.add(new Gob(new Rectangle(Double.parseDouble(tokens[1]), 
                                         Double.parseDouble(tokens[2]),
                                         Double.parseDouble(tokens[3]),
                                         Double.parseDouble(tokens[4])), fill, stroke));
                     break;
                  case "Stroke":
                     stroke = new Color(Double.parseDouble(tokens[1]), 
                                         Double.parseDouble(tokens[2]),
                                         Double.parseDouble(tokens[3]),
                                         Double.parseDouble(tokens[4]));
                     break;
                  case "Text":
                     gobList.add(new Gob(new Text(Double.parseDouble(tokens[1]), 
                                          Double.parseDouble(tokens[2]),
                                          fileIn.nextLine()),fill,stroke));
                    break;
              }
           }
        }
      }
      catch (IOException e) {
         Alert alert = new Alert(AlertType.ERROR,"There was an error reading the file: "+filename,
             ButtonType.OK);
         alert.setTitle("File Reading Error");
         alert.setHeaderText("File Reading Error\n"+e.getMessage());
         Optional<ButtonType> result = alert.showAndWait();
         fileRead = false;
            
      }
   }
   
/*   public void saveGobList(String filename) {
      try {
      
      }
      catch (IOException e) {
      
      }
   
   }
*/   
   public void displayStage(Stage stage) {
      this.stage = stage;
      displayStage();         
   }
   
   public void displayStage() {
      if (stage == null)
         this.stage = new Stage();
      Pane p = new Pane();
      Scene scene = new Scene(p, 640, 480); 
      stage.setScene(scene);
      for (Gob s:gobList)
         p.getChildren().add(s.getShape());
      stage.show();
   }  
}
