import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

/*
8x8 Grid -done
Black and white squares -done

8 Pawn
1 King
1 Queen
2 Rook
2 Knight
2 Bishop

piece movements
*/
public class Board extends Application{

Label[][] boardGrid = new Label[9][9];

// creation of player front line pawns
Label playerPawn1 = new Label();
Label playerPawn2 = new Label();
Label playerPawn3 = new Label();
Label playerPawn4 = new Label();
Label playerPawn5 = new Label();
Label playerPawn6 = new Label();
Label playerPawn7 = new Label();
Label playerPawn8 = new Label();

// creation of player back line pieces
Label playerKing = new Label();
Label playerQueen = new Label();

Label playerRook1 = new Label();
Label playerRook2 = new Label();

Label playerBishop1 = new Label();
Label playerBishop2 = new Label();

Label playerKnight1 = new Label();
Label playerKnight2 = new Label();

// creation of opponent front line pawns
Label opponentPawn1 = new Label();
Label opponentPawn2 = new Label();
Label opponentPawn3 = new Label();
Label opponentPawn4 = new Label();
Label opponentPawn5 = new Label();
Label opponentPawn6 = new Label();
Label opponentPawn7 = new Label();
Label opponentPawn8 = new Label();

// creation of opponent back line pieces
Label opponentKing = new Label();
Label opponentQueen = new Label();

Label opponentRook1 = new Label();
Label opponentRook2 = new Label();

Label opponentBishop1 = new Label();
Label opponentBishop2 = new Label();

Label opponentKnight1 = new Label();
Label opponentKnight2 = new Label();


   public static void main(String[] args){
     launch(args);
   }
   
    public void start(Stage mainStage) {
        mainStage.setTitle("Chess");
        
  /*      
               @Override
            public void handle(ActionEvent event) {
                System.out.println("Click");
            }
        });
   */     
        GridPane root = new GridPane();

        
// creates the grid        
        for(int row = 1; row < 9; row++){
           for(int col = 1; col <9; col++){

               boardGrid[row][col] = new Label(" row "+row +" col "+col);              

                boardGrid[row][col].setPrefWidth(119);
                boardGrid[row][col].setPrefHeight(119);
                boardGrid[row][col].setStyle("-fx-Background-color:#deb887; "); 
              
               if(row%2==0 && col%2==0 || row%2==1 && col%2==1){
                  boardGrid[row][col].setStyle("-fx-Background-color:#8b5a2b; ");
               } 
                            
               root.add(boardGrid[row][col], col, row);
           }
        }
             
        mainStage.setScene(new Scene(root, 950, 850));
        mainStage.show();
    }
}