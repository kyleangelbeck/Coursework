package graphicsproject2;
import java.awt.*;
import java.awt.event.*;

public class GraphicsProject2 extends Frame {
   public static void main(String[] args) {
       new GraphicsProject2();
   }
   
   GraphicsProject2() {
      super("Squares on Squares on Squares");
      addWindowListener(new WindowAdapter() {public void windowClosing(WindowEvent e){System.exit(0);}});
      setSize(850, 850);
      add("Center", new CvGraphicsProject2());
      show();
   }
}

class CvGraphicsProject2 extends Canvas {
   int xStart=0, yStart=0;
   int iX(float x){return Math.round(x);}
   int iY(float y){return Math.round(y);}

   public void paint(Graphics g) {  
      //side = square size, n = num of columns/rows
      float side = 60, n = 9,
         xA, yA, xB, yB, xC, yC, xD, yD,
         xA1, yA1, xB1, yB1, xC1, yC1, xD1, yD1, p, q, k;
      //q and p are the offset of each spiraled square
      q = 0.2F; 
      p = 1 - q; 
      //k num of spiraling squares
      k = 10;
      
      for(int i=0; i<n; i++) {
          for(int j=0; j<n; j++) {
            xA = i * side; yA = j * side + side;
            xB = i * side + side; yB = j * side + side;
            xC = i * side + side; yC = j * side;
            xD = i * side; yD = j * side;
            
            for (int tempk=0; tempk<k; tempk++) {  
                   g.drawLine(iX(xA), iY(yA), iX(xB), iY(yB));
                   g.drawLine(iX(xB), iY(yB), iX(xC), iY(yC));
                   g.drawLine(iX(xC), iY(yC), iX(xD), iY(yD));
                   g.drawLine(iX(xD), iY(yD), iX(xA), iY(yA));
                   xA1 = p * xA + q * xB; yA1 = p * yA + q * yB; 
                   xB1 = p * xB + q * xC; yB1 = p * yB + q * yC;
                   xC1 = p * xC + q * xD; yC1 = p * yC + q * yD; 
                   xD1 = p * xD + q * xA; yD1 = p * yD + q * yA; 
                   xA = xA1; xB = xB1; xC = xC1; xD = xD1;
                   yA = yA1; yB = yB1; yC = yC1; yD = yD1;
            }
            if(j!=n-1 || n%2==1) {
                float temp = p;
                p=q;
                q=temp;
            }
          }   
      }
   }
}