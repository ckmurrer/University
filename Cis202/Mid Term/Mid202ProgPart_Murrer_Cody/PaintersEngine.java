// *******************************************************
// * CIS 202 Midterm Exam - Programming Part
// * NAME:  Cody Murrer 1 point
// * FILE:  PaintersEngine.java
// *******************************************************
// Directions:  Replace the ??? through out the code with
//              the appropriate Java code. (30 total points)

import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Shape;
import javafx.scene.shape.Arc;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.scene.shape.Path;
import javafx.scene.shape.Polygon;
import javafx.scene.shape.Polyline;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
import javafx.scene.paint.Color;

import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.ButtonType;

import java.util.Optional;
import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;
import java.io.IOException;

public class PaintersEngine {
   // Declare array list of graphical objects (4 points)
   private MyLinkedList<Gob> gobList = new MyLinkedList<>();
   private Stage stage=null;
   private boolean fileRead = false;
   public void loadGobList(String filename) {
      double[] points;
      Gob[] array2sort;
      int defaultPriority = Integer.MAX_VALUE;
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
               // Create the tokens array by splitting the line on whitespace. (4 points)
               tokens = line.split("\\s");

               // Circle, Ellipse, Line, Polygon, Polyline, Rectangle       
               switch (tokens[0]) {
                  case "Throw":
                     throw new IOException("Arg!"); // Throw a test exception. (3 points)
                  case "Arc":
                     // Add the following shape to the gobList (10 points)
                     // Arc(double centerX, double centerY, double radiusX, 
                     //     double radiusY, double startAngle, double length , optional priority)
                     gobList.add(new Gob(new Arc(Double.parseDouble(tokens[1]),
                                         Double.parseDouble(tokens[2]), 
                                         Double.paraeDouble(tokens[3]),
                                         Double.parseDouble(tokens[4]),
                                         Double.parseDouble(tokens[5]),
                                         Double.parseDouble(tokens[6])), fill, stroke,
                                         tokens.length>7?Integer.parseInt(tokens[7]):defaultPriority));
                     break;
                  case "Circle":
                     gobList.add(new Gob(new Circle(Double.parseDouble(tokens[1]), 
                                         Double.parseDouble(tokens[2]),
                                         Double.parseDouble(tokens[3])), fill, stroke,
                                         tokens.length>4?Integer.parseInt(tokens[4]):defaultPriority));
                     break;                  
                  case "Ellipse":
                     // Add an Ellipse shape with optional priority (5 points)
                     gobList.add(new Gob(new Ellipse(Double.parseDouble(tokens[1]), 
                                         Double.parseDouble(tokens[2]),
                                         Double.parseDouble(tokens[3]),
                                         Double.parseDouble(tokens[4])), fill, stroke,
                                         tokens.length>5?Integer.parseInt(tokens[5]):defaultPriority));
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
                                         Double.parseDouble(tokens[4])), fill, stroke,
                                         tokens.length>5?Integer.parseInt(tokens[5]):defaultPriority));
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
                  case "PolygonP":
                     points = new double[tokens.length-2];
                     for (int i=0; i<points.length; i++) 
                        points[i] = Double.parseDouble(tokens[i+1]);
                     gobList.add(new Gob(new Polygon(points), fill, stroke,
                     Integer.parseInt(tokens[tokens.length-1])));
                     break;
                  case "PolylineP":
                     points = new double[tokens.length-2];
                     for (int i=0; i<points.length; i++) 
                        points[i] = Double.parseDouble(tokens[i+1]);
                     gobList.add(new Gob(new Polyline(points), fill, stroke,
                     Integer.parseInt(tokens[tokens.length-1])));
                     break;
                  case "Rectangle":
                     gobList.add(new Gob(new Rectangle(Double.parseDouble(tokens[1]), 
                                         Double.parseDouble(tokens[2]),
                                         Double.parseDouble(tokens[3]),
                                         Double.parseDouble(tokens[4])),
                                         fill, stroke,
                                         tokens.length>5?Integer.parseInt(tokens[5]):defaultPriority));
                     break;
                  case "Sort":
                     array2sort = gobList.toArray();
                     // Call the heapSort on array2sort (3 points)
                     heap.add(array2sort);
                     gobList.clear();
                     for (Gob g:array2sort)
                        gobList.add(g);
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
                                                  fileIn.nextLine()),
                                                  fill, stroke,
                                                  tokens.length>3?Integer.parseInt(tokens[3]):defaultPriority));
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
