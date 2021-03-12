import java.util.*;

public class DiscussionTwo {
   int[] array = new int[1000];

  public static void main(String[] args){
   new DiscussionTwo();
  }

  public DiscussionTwo() {
    Thread thread1 = new Thread(new First());
    Thread thread2 = new Thread(new Second());
    thread1.start();
    thread2.start();
  }

  class First implements Runnable {
    public void run() {
      for (int i = 0; i < 10; i++) {
        System.out.println("First Boi");
        int test = i;
        array[i]=test;
        try { Thread.sleep(10); } catch (Exception ex) {
          ex.printStackTrace();
        }
      }
    }
  }

  public void HopeThisWorks() {
    synchronized (this) {
     
    }
  }

  class Second implements Runnable {
    public void run() {
      while (true) {
        System.out.println("Second Boi");
        try { Thread.sleep(10); } catch (Exception ex) {
          ex.printStackTrace();
        }
        synchronized (this) {
          for(int i = 0; i<array.length; i++) {
        	  
            System.out.println(array[i]);
          }
        }
      }
    }
  }
}
