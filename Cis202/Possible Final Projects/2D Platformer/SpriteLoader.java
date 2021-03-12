//http://java-buddy.blogspot.com/2013/01/convert-javaawtimagebufferedimage-to.html

import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.net.URL;

import javax.imageio.ImageIO;

public class SpriteLoader{

   BufferedImage[][] sprites;
   
   public SpriteLoader(String image) throws IOException {
	  URL url = this.getClass().getResource(image);
     
     
	  BufferedImage spriteSheet = ImageIO.read(url);
     
     
     
      int rows = 8;
      int columns = 9;
      int width = spriteSheet.getWidth()/columns;
      int height = spriteSheet.getHeight()/rows;
      sprites = new BufferedImage[rows][columns];
      for(int r = 0; r < rows; r++) {
         for(int c = 0; c < columns; c++) {
            sprites[r][c] = spriteSheet.getSubimage(c * width, r * height, width, height);
         }
      }
   }     
   
   public BufferedImage getSprite(int row, int col){
	   return sprites[row][col];
   }
   
   public BufferedImage[][] getAllSprites(){
	   return sprites;
   }
   
   public Image getSprite(int row, int col, int scaleW, int scaleH){
	   Image i = sprites[row][col].getScaledInstance(scaleW, scaleH, java.awt.Image.SCALE_SMOOTH);
	   return i;
   }
   
   public Image[][] getAllSprites(int scaleW, int scaleH){
	   Image[][] resizedImages = new Image[8][9];
	   for(int r = 0; r < 8; r++) {
         for(int c = 0; c < 9; c++) {
            resizedImages[r][c] = sprites[r][c].getScaledInstance(scaleW, scaleH, java.awt.Image.SCALE_SMOOTH);
         }
      }
	   return resizedImages;
   }
}
