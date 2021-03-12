import javafx.scene.shape.Rectangle;

public class RectStack {
  private Rectangle[] elements;
  private int size;
  public static final int DEFAULT_CAPACITY = 16;

  /** Construct a stack with the default capacity 16 */
  public RectStack() {
    this(DEFAULT_CAPACITY);
  }

  /** Construct a stack with the specified maximum capacity */
  public RectStack(int capacity) {
    elements = new Rectangle[capacity];
  }

  /** Push a new integer into the top of the stack */
  public void push(Rectangle value) {
    if (size >= elements.length) {
      Rectangle[] temp = new Rectangle[elements.length * 2];
      System.arraycopy(elements, 0, temp, 0, elements.length);
      elements = temp;
    }

    elements[size++] = value;
  }

  /** Return and remove the top element from the stack */
  public Rectangle pop() {
    return elements[--size];
  }

  /** Return the top element from the stack */
  public Rectangle peek() {
    return elements[size - 1];
  }

  /** Test whether the stack is empty */
  public boolean empty() {
    return size == 0;
  }

  /** Return the number of elements in the stack */
  public int getSize() {
    return size;
  }
}
