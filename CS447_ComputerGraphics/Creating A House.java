package graphicsproject1;

import java.awt.*;
import java.awt.event.*;

public class GraphicsProject1 extends Frame
{  public static void main(String[] args){new GraphicsProject1();}
   
   GraphicsProject1()
   {  super("GraphicsProject1");
      addWindowListener(new WindowAdapter()
         {public void windowClosing(WindowEvent e){System.exit(0);}});
      setSize(700, 650);
      add("Center", new CvGraphicsProject1());
      show();
   }
}

class CvGraphicsProject1 extends Canvas {
    public void paint(Graphics g) {
        Color brown = new Color(128,64,0);
        Color tan = new Color(210,180,140);
        Color glass = new Color(168,204,215);
        
        //Main house
        g.setColor(brown);
        g.fillRect(100, 225, 400, 325);
        g.setColor(Color.black);
        g.drawRect(100, 225, 400, 325);
        
        //front door
        g.setColor(tan);
        g.fillRect(275,450,50,100);
        g.setColor(Color.black);
        g.drawRect(275,450,50,100);
        
        //door knob
        g.setColor(Color.yellow);
        g.fillOval(305, 500, 10, 10);
        g.setColor(Color.black);
        g.drawOval(305, 500, 10, 10);
        
        //chimney
        g.setColor(Color.red);
        g.fillRect(400,100,35,85);
        g.setColor(Color.black);
        g.drawRect(400,100,35,85);
        
        //Roof
        int[] roofx={75,525,300};
        int[] roofy={225,225,75};
        Polygon roof = new Polygon(roofx,roofy,3);
        g.setColor(brown);
        g.fillPolygon(roof);
        g.setColor(Color.black);
        g.drawPolygon(roof);
        
        //window 1
        g.setColor(glass);
        g.fillRect(125, 425, 125, 75);
        g.setColor(Color.black);
        g.drawRect(125, 425, 125, 75);
        g.drawLine(125, 462, 250, 462);
        g.drawLine(166,425,166,500);
        g.drawLine(208,425,208,500);
        
        //window 2
        g.setColor(glass);
        g.fillRect(350, 425, 125, 75);
        g.setColor(Color.black);
        g.drawRect(350, 425, 125, 75);
        g.drawLine(350, 462, 475, 462);
        g.drawLine(391,425,391,500);
        g.drawLine(433,425,433,500);
        
        //window 3
        g.setColor(glass);
        g.fillRect(125, 275, 125, 75);
        g.setColor(Color.black);
        g.drawRect(125, 275, 125, 75);
        g.drawLine(125, 312, 250, 312);
        g.drawLine(166,275,166,350);
        g.drawLine(208,275,208,350);
        
        //window 4
        g.setColor(glass);
        g.fillRect(350, 275, 125, 75);
        g.setColor(Color.black);
        g.drawRect(350, 275, 125, 75);
        g.drawLine(350, 312, 475, 312);
        g.drawLine(391,275,391,350);
        g.drawLine(433,275,433,350);
        
        //circle window
        g.setColor(glass);
        g.fillOval(265,125,75,75);
        g.setColor(Color.black);
        g.drawOval(265,125,75,75);
        g.drawLine(265,162,340,162);
        g.drawLine(302,125,302,200);
    }
}