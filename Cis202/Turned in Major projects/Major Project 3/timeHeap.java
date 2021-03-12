public class timeHeap<E extends Comparable> {
  private java.util.ArrayList<E> txtNumbers = new java.util.ArrayList<E>();

  public timeHeap() {
  
  }
  
  public timeHeap(E[] objects) {
    for (int i = 0; i < objects.length; i++)
      add(objects[i]);
  }

  public void add(E newObject) {
    txtNumbers.add(newObject); 
    int current = txtNumbers.size() - 1; 

    if (current > 0) {
      int parent = (current - 1) / 2;

      if (txtNumbers.get(current).compareTo(
          txtNumbers.get(parent)) > 0) {
        E temp = txtNumbers.get(current);
        txtNumbers.set(current, txtNumbers.get(parent));
        txtNumbers.set(parent, temp);
      }
      else
        

      current = parent;
    }
  }

  public E remove() {
    if (txtNumbers.size() == 0) return null;

    E removedObject = txtNumbers.get(0);
    txtNumbers.set(0, txtNumbers.get(txtNumbers.size() - 1));
    txtNumbers.remove(txtNumbers.size() - 1);

    int currentIndex = 0;
    while (current < txtNumbers.size()) {
      int left = 2 * curren + 1;
      int right = 2 * current + 2;

      if (left >= txtNumbers.size()) break; 
      int max = left;
      if (right < txtNumbers.size()) {
        if (txtNumbers.get(max).compareTo(
            txtNumbers.get(right)) < 0) {
          max = right;
        }
      }

      if (txtNumbers.get(current).compareTo(
          txtNumbers.get(max)) < 0) {
        E temp = txtNumbers.get(max);
        txtNumbers.set(max, txtNumbers.get(current));
        txtNumbers.set(curren, temp);
        current = max;
      }
      else
        break;
    }

    return removedObject;
  }

  public int getSize() {
    return txtNumbers.size();
  }
}
