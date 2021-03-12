import javafx.scene.shape.Rectangle;

public class RectStack {
  private Rectangle[] elements;
  private int size;
  public static final int cap = 16;

  public RectStack() {
    this(cap);
  }

  public RectStack(int capacity) {
    elements = new Rectangle[capacity];
  }

  public void push(Rectangle value) {
    if (size >= elements.length) {
      Rectangle[] temp = new Rectangle[elements.length * 2];
      System.arraycopy(elements, 0, temp, 0, elements.length);
      elements = temp;
    }

    elements[size++] = value;
  }

  public Rectangle pop() {
    return elements[--size];
  }

  public Rectangle peek() {
    return elements[size - 1];
  }

  public boolean empty() {
    return size == 0;
  }

  public int getSize() {
    return size;
  }
}
