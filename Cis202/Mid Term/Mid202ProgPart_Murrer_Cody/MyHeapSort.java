// *******************************************************
// * CIS 202 Midterm Exam - Programming Part
// * NAME:  Cody Murrer 1 point
// * FILE:  MyHeapSort.java
// *******************************************************
// Directions:  Replace the ??? through out the code with
//              the appropriate Java code. (6 total points)

public class MyHeapSort {
  /** MyHeap sort method */
  public static <E extends Comparable> void heapSort(E[] list) {
    // Create a MyHeap of integers
    MyHeap<E> heap = new MyHeap<E>(list);

    // Remove elements from the heap (5 points)
    for (int i = list.length - 1; i >= 0; i--){
      list[i] = heap.remove();
   }
  }
}
