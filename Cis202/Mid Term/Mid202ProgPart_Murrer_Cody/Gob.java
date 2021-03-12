// *******************************************************
// * CIS 202 Midterm Exam - Programming Part
// * NAME:  Cody Murrer 1 point
// * FILE:  Gob.java  1 point
// *******************************************************
// Directions:  Replace the ??? through out the code with
//              the appropriate Java code. (14 points)

import javafx.scene.shape.Shape;
import javafx.scene.shape.Rectangle;
import javafx.scene.paint.Color;

public class Gob implements Comparable<Gob> {
   private Shape shape;
   private String shapeName;
   private Color fill;
   private Color stroke;
   private int priority;
   
   private static boolean sorted = false;
   
   public Gob(Shape s, Color f, Color st, int priority) {
      this.shape = s;
      
      // Assign the shape name using the getName() method in the getClass() method of the shape object. (6 points)
      this.shapeName = shapeName;
      this.fill = f;
      this.stroke = st;
      this.priority = priority;
      this.shape.setFill(f);
      this.shape.setStroke(st);
      sorted = false;
   }
   
   public Gob(Shape s, Color f, Color st) {
      this(s,f,st,Integer.MAX_VALUE);
   }

   public Gob() {
      this(new Rectangle(10,10,100,100),Color.WHITE,Color.BLACK,Integer.MAX_VALUE);
   }

   public void setPriority(int p) {
      this.priority = p;
   }
   
   public Color getFill() {
      return fill;
   }
   
   public Color getStroke() {
      return stroke;
   }
   
   public Shape getShape() {
      return shape;
   }
   
   public String getShapeName() {
      return shapeName;
   }
   
   public static void setSorted(boolean srt) {
      sorted = srt;
   }

   public int getPriority() {
      return this.priority;
   }

   
   public static boolean getSorted() {
      return sorted;
   }
   
   public int compareTo(Gob o) {
      // Return the difference between this object's priority and the parameter's priority. (6 points)
          if (getPriority() > o.getPriority())
      return 1;
    else if (getPriority() < o.getPriority())
      return -1;
    else
      return 0;
   }
   
   public String toString() {
      return getShapeName()+" "+getPriority();
   }
}
