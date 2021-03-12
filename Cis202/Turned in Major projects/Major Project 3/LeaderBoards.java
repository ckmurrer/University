// **********************************************************************************
// Title: Mazes
// Author: Cody Murrer
// Course Section: CIS202-HYB1 (Seidel) Spring 2019
// File: LeaderBoards.java
// Description: An arcade style leaderboard listed to 10 with the top 10 times on each maze with the 3 letter initials
// **********************************************************************************
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.WindowEvent;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class LeaderBoards{

Button btnReturn = new Button();
Button btnMOne = new Button();
Button btnMTwo = new Button();
Button btnMThree = new Button();


private StackPane leaderBoard;
   
  public static <E extends Comparable> void heapSort(E[] list) {

    timeHeap<E> heap = new timeHeap<E>();

    for (int i = 0; i < list.length; i++)
      heap.add(list[i]);

    for (int i = list.length - 1; i >= 0; i--)
      list[i] = heap.remove();
  }
  
  public static void reader() {
		File check = new File("MazeOneTimes.txt");		
		Scanner scan;
		try {
			scan = new Scanner(check);
			while (scan.hasNextLine()) {
 
	      
            int count = 1;
            Integer[] list = new Integer[count];
            list[count] = Integer.parseInt(scan.nextLine());
            count++;
            
				System.out.println(list.length); 
			  // heapSort(list);
			}
			     
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

  public static void main(String[] args) {
    new LeaderBoards();
  }   
   public LeaderBoards(){
      reader();
	   leaderBoard = new StackPane();
   }
      
   public StackPane getLeaderBoards(){
      return leaderBoard;
   }
}