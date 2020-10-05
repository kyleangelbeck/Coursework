/*
Kyle Angelbeck
Computer Graphics Project 4
*/

package graphicsproject4;
import java.awt.*;
import java.awt.event.*;
import java.util.Scanner;
import java.io.File;

public class GraphicsProject4 extends Frame {
    public static void main(String[] args) {
        new GraphicsProject4();
    }
    
    GraphicsProject4() {
        addWindowListener(new WindowAdapter() {public void windowClosing(WindowEvent e){System.exit(0);}});
        setSize(1200, 800);
        add("Center", new CvGraphicsProject4());
        show();
    }
}

class CvGraphicsProject4 extends Canvas {
    public void paint(Graphics g) {
        int r = 20;     //radius of circle
        
        //setup scanner
        Scanner s = null;
        File in = new File("C:/Users/Kyle/Desktop/Graphics/GraphicsProject4/src/graphicsproject4/Input3.txt");
        try{
            s = new Scanner(in);
        } catch(Exception e) {}
        
        //variables from file
        @SuppressWarnings("null")
        int posX = s.nextInt(), posY = s.nextInt();     //initial position
        double initialDir = s.nextDouble();             //initial direction
        double dir = initialDir;                        //direction that changes
        int N = s.nextInt();                            //number of lines
        int polyPoints = s.nextInt();                   //number of polygon points
        int[] polygonX = new int[polyPoints];           //array of polygon x coords
        int[] polygonY = new int[polyPoints];           //array of polygon y coords
        for(int i = 0; i < polyPoints; i++) {           //fills coord arrays
            polygonX[i]=s.nextInt();
            polygonY[i]=s.nextInt();
        }
        
        /* USA Polygon
        int[] polygonX = {18, 28, 38, 68, 76, 94, 114, 136, 136, 152,
                          183, 182, 212, 227, 238, 224, 227, 245, 240, 250,
                          248, 251, 252, 270, 260, 252, 232, 200, 205, 192,
                          190, 180, 187, 152, 132, 115, 53, 8, 0, 15};
        int[] polygonY = {65, 63, 48, 32, 36, 18, 20, 0, 5, 26,
                          26, 34, 36, 4, 10, 46, 68, 98, 116, 132,
                          135, 165, 172, 187, 198, 186, 185, 155, 153, 142,
                          177, 162, 153, 185, 184, 186, 184, 192, 100, 80};*/
        //draw polygon
        Polygon polygon = new Polygon(polygonX, polygonY, polyPoints);
        g.setColor(Color.black);
        g.drawPolygon(polygon);
        
        //draw circle
        g.drawOval(posX-(r/2),posY-(r/2),r,r);      //subtract so that circle is centered on posX,posY
        
        //draw lines
        for(int i = 0; i<N; i++) {
            dir+=(2 * Math.PI / N);
            double tempX = posX, tempY=posY;
            while(polygon.contains(new Point((int)tempX,(int)tempY))){
                tempX += Math.cos(dir);
                tempY += Math.sin(dir);
            }
            //line starts on circle, not in the center
            g.drawLine((int)(posX+(r/2)*Math.cos(dir)),(int)(posY+(r/2)*Math.sin(dir)),(int)tempX,(int)tempY);
        }
        
        //draw starting direction line
        g.drawLine(posX,posY,(int)(posX+(r/2)*Math.cos(initialDir)),(int)(posY-(r/2)*Math.sin(initialDir)));
    }
}