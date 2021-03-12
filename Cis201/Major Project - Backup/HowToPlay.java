import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class HowToPlay{

Label lblTitle = new Label();

Button btnPawn = new Button();
Button btnRook = new Button();
Button btnKnight = new Button();
Button btnBishop = new Button();
Button btnQueen = new Button();
Button btnKing = new Button();
Button btnReturn = new Button();

private StackPane howTo;
private StackPane pawn;
private StackPane rook;
private StackPane knight;
private StackPane bishop;
private StackPane queen;
private StackPane king;  

   
   public static void main(String[] args){
      new HowToPlay();
   }
   
   public HowToPlay(){
   
       howTo = new StackPane();
       pawn = new StackPane();
       rook = new StackPane();
       knight = new StackPane();
       bishop = new StackPane();
       queen = new StackPane();
       king = new StackPane();
       
       lblTitle.setText("How To Play");
  
       btnReturn.setText("Return");
       btnReturn.setTranslateY(120);
// improvement 3 - instead of a big interface with lots of labels i had split them into scenes*********************************************************************************************       
       
// set up multiple scenes for each piece type

// general info and rules

// pawn rules scene
      btnPawn.setText("Pawn Rules");
      btnPawn.setTranslateY(60);      
      btnPawn.setOnAction(new EventHandler<ActionEvent>() {       
      @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnPawn){
               pNP();
            }
         }
      });

// rook rules scene
      btnRook.setText("Rook Rules");      
      btnRook.setOnAction(new EventHandler<ActionEvent>() {       
      @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnRook){
               rKP();
            }
         }
      });

// knight rules scene
      btnKnight.setText("Knight Rules");      
      btnKnight.setOnAction(new EventHandler<ActionEvent>() {       
      @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnKnight){
               kTP();
            }
         }
      });

// bishop rules scene   
      btnBishop.setText("Bishop Rules");
      btnBishop.setOnAction(new EventHandler<ActionEvent>() {       
      @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnBishop){
               bPP();
            }
         }
      });

// queen rules scene 
      btnQueen.setText("Queen Rules");      
      btnQueen.setOnAction(new EventHandler<ActionEvent>() {       
      @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnQueen){
               qNP();
            }
         }
      });

// king rules scene             
      btnKing.setText("King Rules");      
      btnKing.setOnAction(new EventHandler<ActionEvent>() {       
      @Override
         public void handle(ActionEvent event) {
            if(event.getSource()==btnKing){
               kGP();
            }
         }
      });
      
// adds nodes to parent     
      howTo.getChildren().add(lblTitle);  
      howTo.getChildren().add(btnPawn); 
      howTo.getChildren().add(btnRook); 
      howTo.getChildren().add(btnBishop); 
      howTo.getChildren().add(btnKnight); 
      howTo.getChildren().add(btnQueen); 
      howTo.getChildren().add(btnKing);  
   }

// improvement 4 - decided to put each scene within its own method to make the code easier to read*********************************************************************************************************************

// improvement 5 - to show players the different pieces that are being talked about i included the black and white varients of the pieces into the rules pages*****************************************************************

// creates the pawn rule scene   
   public void pNP(){
   
      Label bPawnShow = new Label();
      Label wPawnShow = new Label();
// sets thumbnail images         
      try{          
         FileInputStream blackPawn = new FileInputStream("Images/black_pawn.png");
         FileInputStream whitePawn = new FileInputStream("Images/white_pawn.png"); 
         
         Image wPawn = new Image(whitePawn);
         ImageView wP = new ImageView(wPawn);         
         Image bPawn = new Image(blackPawn);
         ImageView bP = new ImageView(bPawn);                  
         
         bPawnShow.setGraphic(bP);
         wPawnShow.setGraphic(wP);
      }catch(FileNotFoundException UhOh) { 
         System.out.println(UhOh.getMessage());
      }
// creates rules
      Label pTitle = new Label("Pawn Rules");
      Label pR1a = new Label("1a) The pawn can only move one forward space at a time.");
      Label pR1b = new Label("1b) If the piece has not been moved yet it can move two spaces forward.");
      Label pR2 = new Label("2) The pawn can only move to forward spaces.");
      Label pR3 = new Label("3) The piece can only move diagonal  when attacking moving .");
      Label pR4 = new Label("4) If the piece reaches the other players side of the board it becomes a queen piece.");

//changes to pawn rule scene      
      howTo.setVisible(false);                
      btnReturn.setText("Return");
      pawn.getChildren().addAll(bPawnShow,wPawnShow,pTitle,pR1a,pR1b,pR2,pR3,pR4);         
      howTo.getScene().setRoot(getPawnPane());
   }

// creates the rook rule scene   
   public void rKP(){
   
      Label bRookShow = new Label();
      Label wRookShow = new Label();
      
// sets thumbnail images         
      try{          
         FileInputStream blackRook = new FileInputStream("Images/black_rook.png");
         FileInputStream whiteRook = new FileInputStream("Images/white_rook.png"); 
         
         Image wRook = new Image(whiteRook);
         ImageView wR = new ImageView(wRook);         
         Image bRook = new Image(blackRook);
         ImageView bR = new ImageView(bRook);                  
         
         bRookShow.setGraphic(bR);
         wRookShow.setGraphic(wR);
      }catch(FileNotFoundException UhOh) { 
         System.out.println(UhOh.getMessage());
      }
// creates rules
      Label rTitle = new Label("Rook Rules");
      Label rR1a = new Label("1a) The rook can move as many spaces as possible.");
      Label rR1b = new Label("1b) The rook can only move forward, backwards, and sideways.");
      Label rR2 = new Label("2) This piece can attack other pieces by moving forward, backwards, or sideways.");
      Label rR3a = new Label("3a) there is a move called castling you can preform if piece hasnt been moved");
      Label rR3b = new Label("3b) castling allows the king to trade places with the rook.");
      
//switches to rook rule scene      
      howTo.setVisible(false);                
      btnReturn.setText("Return");
      rook.getChildren().addAll(bRookShow,wRookShow,rTitle,rR1a,rR1b,rR2,rR3a,rR3b);           
      howTo.getScene().setRoot(getRookPane());
   }

// creates the knight rule scene     
   public void kTP(){
      Label bKnightShow = new Label();
      Label wKnightShow = new Label();   
      
// sets thumbnail images        
      try{          
         FileInputStream blackKnight = new FileInputStream("Images/black_knight.png");
         FileInputStream whiteKnight = new FileInputStream("Images/white_knight.png"); 
         
         Image wKnight = new Image(whiteKnight);
         ImageView wK = new ImageView(wKnight);         
         Image bKnight = new Image(blackKnight);
         ImageView bK = new ImageView(bKnight);                  
         
         bKnightShow.setGraphic(bK);
         wKnightShow.setGraphic(wK);
      }catch(FileNotFoundException UhOh) { 
         System.out.println(UhOh.getMessage());
      }
// creates rules      
      Label kTitle = new Label("Knight Rules");
      Label kR1 = new Label("1) The knight can only move in an L shape in any orientation.");
      Label kR2 = new Label("2) This piece can only take another piece if the other piece is at the end of the L on your move.");
      Label kR3 = new Label("3) A unique move this piece can do is jump other pieces.");

//switches to knight rule scene       
      howTo.setVisible(false);                
      btnReturn.setText("Return");
      knight.getChildren().addAll(bKnightShow,wKnightShow,kTitle,kR1,kR2,kR3);           
      howTo.getScene().setRoot(getKnightPane());
   }

// creates the bishop rule scene     
   public void bPP(){
      Label bBishopShow = new Label();
      Label wBishopShow = new Label();
      
// sets thumbnail images         
      try{          
         FileInputStream blackBishop = new FileInputStream("Images/black_bishop.png");
         FileInputStream whiteBishop = new FileInputStream("Images/white_bishop.png"); 
         
         Image wBishop = new Image(whiteBishop);
         ImageView wB = new ImageView(wBishop);         
         Image bBishop = new Image(blackBishop);
         ImageView bB = new ImageView(bBishop);                  
         
         bBishopShow.setGraphic(bB);
         wBishopShow.setGraphic(wB);
      }catch(FileNotFoundException UhOh) { 
         System.out.println(UhOh.getMessage());
      }
// creates rules      
      Label bTitle = new Label("Bishop Rules");
      Label bR1 = new Label("1) This piece can only move in a diagonal manor.");
      Label bR2 = new Label("2) The bishop can only take other pieces by going diagonally");

// switches to bishop rule scene      
      howTo.setVisible(false);                
      btnReturn.setText("Return");
      bishop.getChildren().addAll(bBishopShow,wBishopShow,bTitle,bR1,bR2);           
      howTo.getScene().setRoot(getBishopPane());
   }

// creates queen rule scene   
   public void qNP(){
      Label bQueenShow = new Label();
      Label wQueenShow = new Label(); 
      
// creates thumbnail images       
      try{          
         FileInputStream blackQueen = new FileInputStream("Images/black_queen.png");
         FileInputStream whiteQueen = new FileInputStream("Images/white_queen.png"); 
         
         Image wQueen = new Image(whiteQueen);
         ImageView wQ = new ImageView(wQueen);         
         Image bQueen = new Image(blackQueen);
         ImageView bQ = new ImageView(bQueen);                  
         
         bQueenShow.setGraphic(bQ);
         wQueenShow.setGraphic(wQ);
      }catch(FileNotFoundException UhOh) { 
         System.out.println(UhOh.getMessage());
      }

// creates rules
      Label qTitle = new Label("Queen Rules");
      Label qR1 = new Label("1) The queen can move in any way around the board it just cant jump pieces");

// switches to queen rules scene    
      howTo.setVisible(false);                
      btnReturn.setText("Return");
      queen.getChildren().addAll(bQueenShow,wQueenShow,qTitle,qR1);           
      howTo.getScene().setRoot(getQueenPane());
   }
 
// creates king rule scene   
   public void kGP(){
      Label bKingShow = new Label();
      Label wKingShow = new Label(); 
 
// creates thumbnails        
      try{          
         FileInputStream blackKing = new FileInputStream("Images/black_king.png");
         FileInputStream whiteKing = new FileInputStream("Images/white_king.png"); 
         
         Image wKing = new Image(whiteKing);
         ImageView wK = new ImageView(wKing);         
         Image bKing = new Image(blackKing);
         ImageView bK = new ImageView(bKing);                  
         
         bKingShow.setGraphic(bK);
         wKingShow.setGraphic(wK);
      }catch(FileNotFoundException UhOh) { 
         System.out.println(UhOh.getMessage());
      }
// creates rules      
      Label kTitle = new Label("King Rules");
      Label kR1 = new Label("1) The king is the most important piece if it gets captured you lose");
      Label kR2a = new Label("2a) The king is much like a pawn it can only move one space at a time.");
      Label kR2b = new Label("2b) The king can move diagonal, forwards, backwards, and side to side to move or capture another piece.");
      
      howTo.setVisible(false);                
      btnReturn.setText("Return");

      king.getChildren().addAll(bKingShow,wKingShow,kTitle,kR1,kR2a,kR2b);           
      howTo.getScene().setRoot(getKingPane());
   }
   
   public StackPane getPawnPane(){
      return pawn;
   }

   public StackPane getRookPane(){
      return rook;
   }

   public StackPane getKnightPane(){
      return knight;
   }

   public StackPane getBishopPane(){
      return bishop;
   }

   public StackPane getQueenPane(){
      return queen;
   }

   public StackPane getKingPane(){
      return king;
   }

   public StackPane getHowToPane(){
      return howTo; 
   }  
}