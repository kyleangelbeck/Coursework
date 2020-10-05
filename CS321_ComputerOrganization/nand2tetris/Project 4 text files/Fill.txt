// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.  @KBD @SCREEN

@24576
D=A
@last
M=D		//last=24576
(START)
@SCREEN
D=A		//D=address of first screen bit
@i
M=D		//i=address of first screen bit
@KBD	
D=M		//D=Keyboard
@FILL
D;JNE	//Jump to fill if keyboard is not 0.

(NOFILL)
@i
A=M		//goes to address of screen
M=0		//screen bit=0
@i
M=M+1	//increments screen address
D=M		//D= address of screen bit
@last
D=D-M	//D=D-last bit
@START
D;JEQ	//if address of screen bit is equal to after the last bit, jump to start
@NOFILL
0;JMP	//else jump to nofill

(FILL)
@i
A=M		//goes to address of screen
M=-1	//screen bit=0
@i
M=M+1	//increments screen address
D=M		//D= address of screen bit
@last
D=D-M	//D=D-last bit
@START
D;JEQ	//if address of screen bit is equal to after the last bit, jump to start
@FILL
0;JMP	//else jump to fill