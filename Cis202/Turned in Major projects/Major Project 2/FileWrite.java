import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

import javafx.geometry.Pos;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.control.TextInputDialog;
import javafx.stage.Modality;
import javafx.stage.Stage;

public class FileWrite {

	public static void display(String title, String message, String file, int min, int sec) {

		writer(file,min,sec);
		reader(file,min,sec);
		
		Stage popUp = new Stage();
		
		popUp.initModality(Modality.APPLICATION_MODAL);
		popUp.setTitle(title);
		popUp.setMinWidth(250);
		popUp.setMinHeight(250);
		
		Label congrats = new Label();
		congrats.setText(message+": "+(String.format("%02d:%02d", min,(sec-1))));
		
		TextInputDialog name = new TextInputDialog();
		name.setWidth(50);
		name.setHeight(10);
		
		Button close = new Button("OK");
		close.setOnAction(new EventHandler<ActionEvent>() {       
	         @Override
	         public void handle(ActionEvent event) {
	        	 MainScreen main = new MainScreen();
	        	 MazeSelect ms = new MazeSelect();                  
	             main.getMainStage().getScene().setRoot(ms.getSelect());
	             main.getMainStage().centerOnScreen();
	             
	             popUp.close();
	        	 
	         }
	      });    
	
		VBox root = new VBox();
		root.getChildren().addAll(congrats,close);
		root.setAlignment(Pos.CENTER);
		
		Scene scene = new Scene(root);
		popUp.setScene(scene);
		popUp.showAndWait();
	}
	
	public static void writer(String file, int min,int sec) {
		try {
			FileWriter fw = new FileWriter(file,true);
			//BufferedWriter bw = new BufferedWriter(fw);
         
         int nt = min+(sec-1);
         
			fw.write(nt);
			//fw.newLine();
			fw.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void reader(String file, int min, int sec) {
		File check = new File(file);		
		Scanner scan;
		try {
			scan = new Scanner(check);
			while (scan.hasNextLine()) {
				
				System.out.println(scan.nextLine()); 
			
			}
			     
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
