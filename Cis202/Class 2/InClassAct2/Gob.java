import javafx.scene.shape.Shape;
import javafx.scene.paint.Color;

public class Gob {
   Shape shape;
   Color fill;
   Color stroke;
   
   public Gob(Shape s, Color f, Color st) {
      this.shape = s;
      this.fill = f;
      this.stroke = st;
      this.shape.setFill(f);
      this.shape.setStroke(st);
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
}
