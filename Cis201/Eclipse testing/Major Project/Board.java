import javafx.scene.input.MouseEvent;
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

piece movements - almost done have registered click events now -------------> ask for help after class 
piece capturing - not started

alternating turns - not started

checking for check and checkmate - not started
*/
public class Board{
//even or odd number indicator
private static int evenOrOdd=0;
// creates the label array variables
Label[][] bwPieces = new Label[9][9];
Label[][] boardGrid = new Label[9][9];
// might be scrapped later
boolean select = false;

static int yOne,xOne,yTwo,xTwo,nX,nY;
private static int count = 0;

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
 
// creates boards colored squares
            if(row%2==0 && col%2==0 || row%2==1 && col%2==1){
               boardGrid[row][col].setStyle("-fx-Background-color:#deb887;"); 
            }else{              
               boardGrid[row][col].setStyle("-fx-Background-color:#8b5a2b;");
            }
            gameBoard.add(boardGrid[row][col], col, row);            
         }
      }
   }
   
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
                  Image bPawn = new Image(blackPawn);
                  ImageView imageView = new ImageView(bPawn);
                  
                  bwPieces[row][col].setGraphic(imageView);
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
                  
            gameBoard.add(bwPieces[row][col], col, row); 

            final  int rw = row;   
            final  int cl = col; 
           
            bwPieces[row][col].addEventHandler(MouseEvent.MOUSE_CLICKED, e -> {
            	 
                  if(evenOrOdd==0){                                                	   
                     yOne = GridPane.getRowIndex(bwPieces[rw][cl]);
                     xOne = GridPane.getColumnIndex(bwPieces[rw][cl]);                     
                     System.out.println("Even turn  Row One: "+ yOne +" Col One: "+xOne);
                     
                  }else {    
                	  
                     yTwo = GridPane.getRowIndex(bwPieces[rw][cl]);
                     xTwo = GridPane.getColumnIndex(bwPieces[rw][cl]);
                     
                     System.out.println("Odd turn Row Two: "+yTwo+" Col Two: "+xTwo);
                     
                     
                     
                     nY = yTwo - yOne;
                     nX = xTwo - xOne;
                     
                      GridPane.setRowIndex(bwPieces[rw][cl], yOne+1);
                      GridPane.setColumnIndex(bwPieces[rw][cl],xOne+nX);
                      
                      System.out.println(nY);
                      System.out.println(nX);
                      
                /*      
                     yTwo = 0;
                     yOne = 0;
                     xOne = 0;
                     xTwo = 0;
             */
                     count++;
                  } 

                  switchEvenOdd();
                    
            });//end Move event Handler
         }// for col end  
      }// for row end
   }// boardPieces draws the board, handles click movement
      
// allows gameBoard to be called in Main.java
   public GridPane getBoardPane(){
      return gameBoard;
   }
}