 import javafx.scene.input.MouseEvent;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
/*
8x8 Grid - done
alternating squares - done

8 Pawn per side - placed / done
1 King per side - placed / done
1 Queen per side - placed / done
2 Rook - per side - placed / done
2 Knight per side - placed / done
2 Bishop per side - placed / done

piece movements - almost done 
piece capturing - not started

alternating turns - done

checking for check and checkmate - not started
*/
public class Board{

// creates the label array variables
Label[][] bwPieces = new Label[9][9];
Label[][] boardGrid = new Label[9][9];

// ints used to store the number location of the pieces on gameBoard
private static int yOne,xOne,yTwo,xTwo;

//even or odd number indicator
private static int evenOrOdd=0;

// images test
public Image bPawn;
public ImageView bP;

private GridPane gameBoard = new GridPane();

   public static void main(String[] args){
      new Board();
   }

   public Board(){
      boardBackground();
      boardPieces();
   }

   public void boardBackground(){
// creates the grid        
      for(int row = 1; row < 9; row++){
         for(int col = 1; col < 9; col++){

            boardGrid[row][col] = new Label();
            boardGrid[row][col].setPrefWidth(100);
            boardGrid[row][col].setPrefHeight(100);
// improvement number 1 - instead of having squares back and white they are two toned brown**************************************************************************************************
// creates boards colored squares and adds them to the scene
            if(row%2==0 && col%2==0 || row%2==1 && col%2==1){
               boardGrid[row][col].setStyle("-fx-Background-color:#deb887;"); 
            }else{              
               boardGrid[row][col].setStyle("-fx-Background-color:#8b5a2b;");
            }
            gameBoard.add(boardGrid[row][col], col, row);            
         }
      }
   }
   
// method used to alternate clicks (used in event handler)   
   public void switchEvenOdd(){
     evenOrOdd = ((evenOrOdd == 0) ? 1:0);
   }
   
    public void boardPieces(){
// for loop to set the rows and columns of each piece
      for(int row = 1; row < 9; row++){
         for(int col = 1; col < 9; col++){

            bwPieces[row][col] = new Label();
            bwPieces[row][col].setPrefWidth(100);
            bwPieces[row][col].setPrefHeight(100);
            bwPieces[row][col].setStyle("-fx-Background-color: transparent;");
            
// b pawn           
            if(row == 2){
// trys to find piece image but if not found prints error message in console               
               try{          
                  FileInputStream blackPawn = new FileInputStream("Images/black_pawn.png");
                  bPawn = new Image(blackPawn);
                  bP = new ImageView(bPawn);
                  
                  bwPieces[row][col].setGraphic(bP);
               }catch(FileNotFoundException UhOh) { 
                  System.out.println(UhOh.getMessage());
               }
              
// b rook               
            }else if(row == 1 && col == 1 || row == 1 && col == 8){
// trys to find piece image but if not found prints error message in console               
               try{              
                  FileInputStream blackRook = new FileInputStream("Images/black_rook.png");
                  Image bRook = new Image(blackRook);
                  ImageView imageView = new ImageView(bRook);

                  bwPieces[row][col].setGraphic(imageView);     

               }catch(FileNotFoundException UhOh){
                  System.out.println(UhOh.getMessage());
               }   
               
// b knight               
            }else if(row == 1 && col == 2 || row == 1 && col == 7){
// trys to find piece image but if not found prints error message in console            
               try{
                  FileInputStream blackKnight = new FileInputStream("Images/black_knight.png");
                  Image bKnight = new Image(blackKnight);
                  ImageView imageView = new ImageView(bKnight);
                  
                  bwPieces[row][col].setGraphic(imageView);
               
               }catch(FileNotFoundException UhOh){
                  System.out.println(UhOh.getMessage());
               }
               
// b bishop              
            }else if(row == 1 && col == 3 || row == 1 && col == 6){
// trys to find piece image but if not found prints error message in console               
               try{
                  FileInputStream blackBishop = new FileInputStream("Images/black_bishop.png");
                  Image bBishop = new Image(blackBishop);
                  ImageView imageView = new ImageView(bBishop);
                  
                  bwPieces[row][col].setGraphic(imageView);
                  
               }catch(FileNotFoundException UhOh){
                  System.out.println(UhOh.getMessage());
               } 
               
// b queen               
            }else if(row == 1 && col == 4){
// trys to find piece image but if not found prints error message in console
               try{
                  FileInputStream blackQueen = new FileInputStream("Images/black_queen.png");
                  Image bQueen = new Image(blackQueen);
                  ImageView imageView = new ImageView(bQueen);
               
                  bwPieces[row][col].setGraphic(imageView);
               
               }catch(FileNotFoundException UhOh){
                  System.out.println(UhOh.getMessage());
               }
               
// b king               
            }else if(row == 1 && col == 5){ 
// trys to find piece image but if not found prints error message in console
               try{
                  FileInputStream blackKing = new FileInputStream("Images/black_king.png");
                  Image bKing = new Image(blackKing);
                  ImageView imageView = new ImageView(bKing);
                  
                  bwPieces[row][col].setGraphic(imageView); 
               
               }catch(FileNotFoundException UhOh){
                  System.out.println(UhOh.getMessage());
               }
               
// w pawn
            }else if(row == 7){
// trys to find piece image but if not found prints error message in console
               try{
                  FileInputStream whitePawn = new FileInputStream("Images/white_pawn.png");
                  Image wPawn = new Image(whitePawn);
                  ImageView imageView = new ImageView(wPawn);
                  
                  bwPieces[row][col].setGraphic(imageView);

               }catch(FileNotFoundException UhOh){
                  System.out.println(UhOh.getMessage());
               }
               
// w rook
            }else if(row == 8 && col == 1 || row == 8 && col == 8){
// trys to find piece image but if not found prints error message in console
               try{
                  FileInputStream whiteRook = new FileInputStream("Images/white_rook.png");
                  Image wRook = new Image(whiteRook);
                  ImageView imageView = new ImageView(wRook);
                  
                  bwPieces[row][col].setGraphic(imageView); 

               }catch(FileNotFoundException UhOh){
                  System.out.println(UhOh.getMessage());
               }

// w knight
            }else if(row == 8 && col == 2 || row == 8 && col == 7){
// trys to find piece image but if not found prints error message in console
               try{
                  FileInputStream whiteKnight = new FileInputStream("Images/white_knight.png");
                  Image wKnight = new Image(whiteKnight);
                  ImageView imageView = new ImageView(wKnight);
               
                  bwPieces[row][col].setGraphic(imageView); 

               }catch(FileNotFoundException UhOh){
                  System.out.println(UhOh.getMessage());            
               }   
               
// w bishop 
            }else if(row == 8 && col == 3 || row == 8 && col == 6){  
// trys to find piece image but if not found prints error message in console
               try{
                  FileInputStream whiteBishop = new FileInputStream("Images/white_bishop.png");
                  Image wBishop = new Image(whiteBishop);
                  ImageView imageView = new ImageView(wBishop);

                  bwPieces[row][col].setGraphic(imageView); 

               }catch(FileNotFoundException UhOh){
                  System.out.println(UhOh.getMessage());
               }

// w queen
            }else if(row == 8 && col == 4){
// trys to find piece image but if not found prints error message in console
               try{
                  FileInputStream whiteQueen = new FileInputStream("Images/white_queen.png");
                  Image wQueen = new Image(whiteQueen);
                  ImageView imageView = new ImageView(wQueen);
                  
                  bwPieces[row][col].setGraphic(imageView);

               }catch(FileNotFoundException UhOh){
                  System.out.println(UhOh.getMessage());
               }

// w king          
            }else if(row == 8 && col == 5){
// trys to find piece image but if not found prints error message in console
               try{
                  FileInputStream whiteKing = new FileInputStream("Images/white_king.png");
                  Image wKing = new Image(whiteKing);
                  ImageView imageView = new ImageView(wKing);
                  
                  bwPieces[row][col].setGraphic(imageView); 

               }catch(FileNotFoundException UhOh){
                  System.out.println(UhOh.getMessage());
               }           
            }
            
            final  int rw = row;   
            final  int cl = col; 
// creates event handler for pieces     
            bwPieces[row][col].addEventHandler(MouseEvent.MOUSE_CLICKED, e -> {
            	 
               if(evenOrOdd==0){                                                	   
                  yOne = gameBoard.getRowIndex(bwPieces[rw][cl]);
                  xOne = gameBoard.getColumnIndex(bwPieces[rw][cl]);
                     
               }else {                          
                  yTwo = gameBoard.getRowIndex(bwPieces[rw][cl]);
                  xTwo = gameBoard.getColumnIndex(bwPieces[rw][cl]);

// improvment number two - instead of having movevevents within the event handle i put them into their seperate methods************************************************************************************************** 
// black                  
                  if(yOne == 2){
                     bPawn();
                  }else if(yOne == 1 && xOne == 1 || yOne == 1 && xOne == 8){
                     bRook();
                  }else if(yOne == 1 && xOne == 2 || yOne == 1 && xOne == 7){
                     bKnight();
                  }else if(yOne == 1 && xOne == 3 || yOne == 1 && xOne == 6){
                     bBishop();
                  }else if(yOne == 1 && xOne == 4){
                     bQueen();
                  }else if(yOne == 1 && xOne == 5){
                     bKing();
                  }
// white
                  if(yOne == 7){
                     wPawn();
                  }else if(yOne == 8 && xOne == 1 || yOne == 8 && xOne == 8 ){
                     wRook();
                  }else if(yOne == 8 && xOne == 2 || yOne == 8 && xOne == 7 ){
                     wKnight();
                  }else if(yOne == 8 && xOne == 3 || yOne == 8 && xOne == 6 ){
                     wBishop();
                  }else if(yOne == 8 && xOne == 4 ){
                     wQueen();
                  }else if(yOne == 8 && xOne == 5 ){
                     wKing();
                  }  
               }              
               switchEvenOdd();                                    
            });//end Move event Handler   
// adds nodes to the board at their row an col positions
            gameBoard.add(bwPieces[row][col], col, row);
         }// for col end
      }// for row end
   }// boardPieces draws the board, handles click movement

// b pawn movement   
   public void bPawn(){
      
      if(yOne != 0 && xOne != 0){
         gameBoard.setRowIndex(bwPieces[yOne][xOne], yTwo);
         gameBoard.setColumnIndex(bwPieces[yOne][xOne], xTwo);
      }else{
         yTwo = 0;
         xTwo = 0;
                  
         xOne = 0;
         yOne = 0;
      }
   }

// b rook movement   
   public void bRook(){
      
      if(yOne != 0 && xOne != 0){
         gameBoard.setRowIndex(bwPieces[yOne][xOne], yTwo);
         gameBoard.setColumnIndex(bwPieces[yOne][xOne], xTwo);
      }else{
         yTwo = 0;
         xTwo = 0;
                  
         xOne = 0;
         yOne = 0;
      }
   }

// b knight movement   
   public void bKnight(){
       
      if(yOne != 0 && xOne != 0){  
         gameBoard.setRowIndex(bwPieces[yOne][xOne], yTwo);
         gameBoard.setColumnIndex(bwPieces[yOne][xOne], xTwo);
      }else{ 
         yTwo = 0;
         xTwo = 0;
                  
         xOne = 0;
         yOne = 0;
      }
   }
 
// b bishop movement   
   public void bBishop(){  
          
      if(yOne != 0 && xOne != 0){  
         gameBoard.setRowIndex(bwPieces[yOne][xOne], yTwo);
         gameBoard.setColumnIndex(bwPieces[yOne][xOne], xTwo);
      }else{ 
         yTwo = 0;
         xTwo = 0;
                  
         xOne = 0;
         yOne = 0;
      }
   }

// b queen movement   
   public void bQueen(){
                  
      if(yOne != 0 && xOne != 0){  
         gameBoard.setRowIndex(bwPieces[yOne][xOne], yTwo);
         gameBoard.setColumnIndex(bwPieces[yOne][xOne], xTwo);
      }else{ 
         yTwo = 0;
         xTwo = 0;
                  
         xOne = 0;
         yOne = 0;
      }
   }

// b king movement   
   public void bKing(){    
      
      if(yOne != 0 && xOne != 0){  
         gameBoard.setRowIndex(bwPieces[yOne][xOne], yTwo);
         gameBoard.setColumnIndex(bwPieces[yOne][xOne], xTwo);
      }else{ 
         yTwo = 0;
         xTwo = 0;
                  
         xOne = 0;
         yOne = 0;
      }
   }  

// w pawn movement   
   public void wPawn(){
   
   if(yOne != 0 && xOne != 0){
         gameBoard.setRowIndex(bwPieces[yOne][xOne], yTwo);
         gameBoard.setColumnIndex(bwPieces[yOne][xOne], xTwo);
      }else{
         yTwo = 0;
         xTwo = 0;
                  
         xOne = 0;
         yOne = 0;
      }
   }

// w rook movement   
   public void wRook(){
   
      if(yOne != 0 && xOne != 0){
         gameBoard.setRowIndex(bwPieces[yOne][xOne], yTwo);
         gameBoard.setColumnIndex(bwPieces[yOne][xOne], xTwo);
      }else{
         yTwo = 0;
         xTwo = 0;
                  
         xOne = 0;
         yOne = 0;
      }
   }

// w knight movement  
   public void wKnight(){
   
      if(yOne != 0 && xOne != 0){
         gameBoard.setRowIndex(bwPieces[yOne][xOne], yTwo);
         gameBoard.setColumnIndex(bwPieces[yOne][xOne], xTwo);
      }else{
         yTwo = 0;
         xTwo = 0;
                  
         xOne = 0;
         yOne = 0;
      }
   }

// w bishop movement  
   public void wBishop(){
   
      if(yOne != 0 && xOne != 0){
         gameBoard.setRowIndex(bwPieces[yOne][xOne], yTwo);
         gameBoard.setColumnIndex(bwPieces[yOne][xOne], xTwo);
      }else{
         yTwo = 0;
         xTwo = 0;
                  
         xOne = 0;
         yOne = 0;
      }
   }

// w queen movement   
   public void wQueen(){
   
      if(yOne != 0 && xOne != 0){
         gameBoard.setRowIndex(bwPieces[yOne][xOne], yTwo);
         gameBoard.setColumnIndex(bwPieces[yOne][xOne], xTwo);
      }else{
         yTwo = 0;
         xTwo = 0;
                  
         xOne = 0;
         yOne = 0;
      }
   }
   
// w king movement   
   public void wKing(){
   
      if(yOne != 0 && xOne != 0){
         gameBoard.setRowIndex(bwPieces[yOne][xOne], yTwo);
         gameBoard.setColumnIndex(bwPieces[yOne][xOne], xTwo);
      }else{
         yTwo = 0;
         xTwo = 0;
                  
         xOne = 0;
         yOne = 0;
      }
   }
      
// allows gameBoard to be called in Main.java
   public GridPane getBoardPane(){
      return gameBoard;
   }
}