import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;

public class WIP {
	
	public static void error() {		
		closing();
		
		Stage errorPopUp = new Stage();
		
		errorPopUp.initModality(Modality.APPLICATION_MODAL);
		errorPopUp.setTitle("Work in Progress");
		errorPopUp.setMinWidth(250);
		errorPopUp.setMinHeight(250);
		
		Label errorLabel = new Label();
		errorLabel.setText("This feature is a work in progress"+"\n"+"Sorry for the inconvenience");
		
		Button close = new Button("OK");
		close.setOnAction(new EventHandler<ActionEvent>() {       
	         @Override
	         public void handle(ActionEvent event) {
	             errorPopUp.close();
	         }
	      });    
	
		VBox layout = new VBox();
		layout.getChildren().addAll(errorLabel,close);
		layout.setAlignment(Pos.CENTER);
		
		Scene scene = new Scene(layout);
		errorPopUp.setScene(scene);
		errorPopUp.showAndWait();		
	}
	
	   private static void closing() {
		   MainScreen ms = new MainScreen();
		   ms.getMainStage().setOnCloseRequest(new EventHandler<WindowEvent>() {
			    @Override 
			    public void handle(WindowEvent t) {
			    	Platform.exit();
			    	System.exit(0);
			    }
		   });
	   }
}
