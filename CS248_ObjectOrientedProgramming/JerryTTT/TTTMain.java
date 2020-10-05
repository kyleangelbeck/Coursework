/**
 @author Kyle Angelbeck
 @author Lauren Marx
 */

import java.io.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class Terminator extends WindowAdapter {
	public void windowClosing(WindowEvent e) {System.exit(0);}
}

public class TTTMain extends JFrame implements ActionListener {
	public static void main(String [] args) {
		TTTMain window=new TTTMain();
	}

    JButton[] buttons = new JButton[9];
	JButton playerFirst, compFirst;
    ImageIcon emptyCircle = new ImageIcon("emptyCircle.png");
    ImageIcon playerCircle = new ImageIcon("blueCircle.png");
    ImageIcon compCircle = new ImageIcon("redCircle.png");

	public TTTMain() {
		setTitle("Jerry Tic-Tac-Toe");
		setSize(1200,850);
		setVisible(true);
		Terminator term=new Terminator();
		addWindowListener(term);

		getContentPane().setBackground(Color.white);

        //9 button creation
        for(int i=0; i<9; i++) {buttons[i]=new JButton(emptyCircle);}
		buttons[0].setBounds(50,175,150,150);
		buttons[1].setBounds(500,175,150,150);
		buttons[2].setBounds(950,175,150,150);
		buttons[3].setBounds(250,400,150,150);
		buttons[4].setBounds(500,400,150,150);
		buttons[5].setBounds(750,400,150,150);
		buttons[6].setBounds(50,625,150,150);
		buttons[7].setBounds(500,625,150,150);
		buttons[8].setBounds(950,625,150,150);
        for(int i=0;i<9;i++) {
        	buttons[i].setBorder(BorderFactory.createEmptyBorder());
            add(buttons[i]);
            buttons[i].addActionListener(this);
        }
		//Button playerFirst
		playerFirst = new JButton("Player Moves First");
		playerFirst.setFont(new Font("Arial", Font.PLAIN, 30));
		playerFirst.setBounds(150,40,350,100);
		playerFirst.setBorder(BorderFactory.createEmptyBorder());
		add(playerFirst);
        playerFirst.addActionListener(this);

		//Button compFirst
		compFirst = new JButton("Computer Moves First");
		compFirst.setFont(new Font("Arial", Font.PLAIN, 30));
		compFirst.setBounds(650,40,350,100);
		compFirst.setBorder(BorderFactory.createEmptyBorder());
		add(compFirst);
        compFirst.addActionListener(this);
	}
	int player;
	boolean inGame = false, gameOver = false;
	int[] gameState = new int[9]; //0=empty, 1=player, 2=comp
	/**
	 @param action that is preformed
	 does action when one of the buttons is pressed
	 */
	public void actionPerformed(ActionEvent e) {
		if(!inGame) {
			if(e.getSource()==playerFirst) {
				inGame=true;
			} else if(e.getSource()==compFirst) {
				inGame=true;
				compMove();
			}
		} else if(getButtonIndex(e)!=-1 && !gameOver) {
        	int buttonIndex=getButtonIndex(e);
            if(gameState[buttonIndex]==0) {
            	gameState[buttonIndex]=1;
                buttons[buttonIndex].setIcon(playerCircle);
                checkWin(1);
                if(!gameOver) {
                	compMove();
                }
            }
		}
	}
	/**
	 @param action that is preformed
	 @return index of the button pressed
	 */
    public int getButtonIndex(ActionEvent e) {
        for(int i=0; i<9; i++) {
            if(e.getSource()==buttons[i]) return i;
        }
        return -1;
    }
	/**
		preforms a computer move
	*/
    public void compMove() {
    	for(int i=0;i<9;i++) {
    		if(gameState[i]==0) {
    			gameState[i]=2;
    			buttons[i].setIcon(compCircle);
    			checkWin(2);
    			break;
    		}
    	}
    }
    int[][] winCond = new int[][] {
   		{0,1,2},
   		{3,4,5},
   		{6,7,8},
   		{0,3,7},
   		{1,5,8},
   		{1,3,6},
   		{2,5,7},
   		{0,4,8},
   		{2,4,6}
    };
    /**
     @param integer for a player
     checks if the inputed player has won the game
     */
    public void checkWin(int player) {
    	boolean win = false;
    	for(int i=0;i<9;i++) {
    		if(gameState[winCond[i][0]]==player && gameState[winCond[i][1]]==player && gameState[winCond[i][2]]==player) {
    			win = true;
    		}
    		if(win) {
    			if(player == 1) {
    				System.out.println("The user won!");
    			} else {
					System.out.println("The computer won");
    			}
    			gameOver=true;
    			break;
    		}
    	}
    }
}