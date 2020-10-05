/*
Kyle Angelbeck
Computer Graphics Project 3
*/

package graphicsproject3;
import java.awt.*;
import java.awt.event.*;
import java.util.Scanner;
import java.io.File;

public class GraphicsProject3 extends Frame {
    public static void main(String[] args) {
        new GraphicsProject3();
    }
   
    GraphicsProject3() {
        addWindowListener(new WindowAdapter() {public void windowClosing(WindowEvent e){System.exit(0);}});
        setSize(1200, 800);
        add("Center", new CvGraphicsProject3());
        show();
    }
}

//x axis is 750 pixels
//y axis is 500 pixels

class CvGraphicsProject3 extends Canvas {
    public void paint(Graphics g) {
        Scanner s = null;
        File in = new File("C:/Users/Kyle/Desktop/Graphics/GraphicsProject3/src/graphicsproject3/Geometry_File3.txt");
        try{
            s = new Scanner(in);
        } catch(Exception e) {}
        
        @SuppressWarnings("null")
        int numBars = s.nextInt();                          //number of bars
        int[] barHeight = new int[numBars];                 //array of values of bars
        String[] barLabel = new String[numBars];            //array of strings for the bar labels
        int barGap = 15;                                    //gap in between each bar
        int barSize = (750-(barGap*(numBars)))/numBars;     //width of bars
        Color[] barColor = new Color[numBars];              //array of colors for each bar
        
        //fill barHeight[] and barLabel[]
        for(int i = 0; i < numBars; i++) {
            barHeight[i] = s.nextInt();
            barLabel[i] = s.nextLine();
            barLabel[i] = s.nextLine();
        }
        //find value of highest bar
        int maxHeight = barHeight[0];
        for(int i = 1; i < numBars; i++) {
            if (barHeight[i] > maxHeight) maxHeight = barHeight[i];
        }
        
        g.setFont(new Font("TimesRoman", Font.PLAIN, 40));
        g.drawString("Bar Chart Text",110,110);
        //x axis
        g.drawLine(100,650,850,650);
        //y axis
        g.drawLine(100,650,100,150);
        
        //create an array of random colors for each bar
        for(int i = 0; i < numBars; i++) {
            barColor[i] = new Color((int)(Math.random()*255+1),(int)(Math.random()*255+1),(int)(Math.random()*255+1)); //Albert was here thx
        }
        
        //create y axis markings
        g.setFont(new Font("TimesRoman", Font.PLAIN, 15));
        for(int i = 0; i < 5; i++) {
           g.drawLine(100,150+(i*100),110,150+(i*100));
           g.drawString(String.valueOf((int)((5-i)*(maxHeight/(5.0)))), 69, 155+(i*100));
        }
        
        //create bars
        for(int i = 0; i < numBars; i++){
            g.setColor(barColor[i]);
            double tempRatio = (double)(barHeight[i]) / maxHeight;      //ratio of bar height to max bar height
            int tempBarHeight = (int)(tempRatio * 500);                 //height of bar in pixels
            //first bar at 115
            g.fillRect(i*(barSize+barGap)+115,650-tempBarHeight,barSize,tempBarHeight);
        }
        
        //create bar labels
        for(int i = 0; i < numBars; i++){
            g.setColor(barColor[i]);
            g.fillRect(950,100 + (i*20),10,10);
            g.setColor(Color.black);
            g.drawString(barLabel[i],970,110 + (i*20));
        }
    }
}