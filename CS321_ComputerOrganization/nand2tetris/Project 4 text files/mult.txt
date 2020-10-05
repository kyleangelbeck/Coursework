 // This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

@i
M=0		//i=0
@R2	
M=0		//sum=0
(LOOP)	//beginning of for statement
@i
D=M		//D=i
@0
D=M-D	//D=M(0)-i
@END
D;JLE	//if D<=0 end (end of for statement)
@i
M=M+1	//i=i+1 (increment)
@R1
D=M		//D=M(1)
@R2
M=M+D	//sum=sum+M(1)
@LOOP
0;JMP	//loop to top
(END)
@END
0;JMP	//inf loop