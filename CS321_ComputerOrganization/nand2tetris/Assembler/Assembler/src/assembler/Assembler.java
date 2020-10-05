import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Assembler	{
    public static void main(String[] args) throws FileNotFoundException, IOException  {

        File in = new File("C:/Users/Kyle/Desktop/nand2tetris/projects/06/pong/Pong.asm");
        Scanner sc = new Scanner(in);
        BufferedWriter writer;
        Symbol[] symbolarray = new Symbol[8000];
        //Creating 
        symbolarray[0]= new Symbol("SP",0);
        symbolarray[1]= new Symbol("LCL",1);
        symbolarray[2]= new Symbol("ARG",2);
        symbolarray[3]= new Symbol("THIS",3);
        symbolarray[4]= new Symbol("THAT",4);
        for(int i = 0; i < 16; i++) {
        symbolarray[i+5]= new Symbol("R" + i,i+5);
        }
        symbolarray[21]= new Symbol("SCREEN",16384);
        symbolarray[22]= new Symbol("KBD",24576);
        
        File out = new File("C:/Users/Kyle/Desktop/nand2tetris/projects/06/pong/Pong.hack");
        out.createNewFile();
        writer = new BufferedWriter(new FileWriter(out));
        
        
        //First Pass
        int counter = 0;
        String line;
        int arraypos=0;
        int symbolcounter=16; //position of the pointer for the next variable symbol
        
        while(sc.hasNextLine()) {
            line = sc.nextLine().trim();
            if(!line.isEmpty() && line.charAt(0) == '/') {   //if it starts with a /, the whole thing is a comment
                line="";
            } else {        //gets rid of comments that arent at beginning
                if(line.isEmpty() && line.indexOf('/') != -1) line=line.substring(0,line.indexOf('/')-1);
            }
            if(!line.isEmpty()) {
                if(line.charAt(0) =='@') {
                    String symbolname = line.substring(1); //gets rid of the @ at the beginning
                    if(!isInArray(symbolarray,symbolname)) { //symbolname isnt in the table
                        if(isInteger(symbolname)) { //isInteger is a selfmade function
                            symbolarray[arraypos] = new Symbol(symbolname, Integer.parseInt(symbolname));
                        } else {
                            symbolarray[arraypos] = new Symbol(symbolname, -1);
                        }
                        arraypos++;
                    }
                } else if(line.charAt(0) == '(') {
                    String symbolname = line.substring(1,line.length()-1); //get rid of '(' at beginning and ')' at end
                    if(!isInArray(symbolarray,symbolname)) { //symbolname isnt in the table
                        symbolarray[arraypos] = new Symbol(symbolname, counter);
                        arraypos++;
                    } else {	//symbol name is in table, need to change the pointer
                        symbolarray[findSymbol(symbolarray,symbolname)].updatePointer(counter);
                    }
                }
            }
            //counter increment
            if(!line.isEmpty() && line.charAt(0) != '(') counter++;
        }
        //Sets pointers of variable symbols
        for(int i=0;i<arraypos; i++) {
            if(symbolarray[i].getPointer() == -1) {
                symbolarray[i].updatePointer(symbolcounter);
                symbolcounter++;
            }
        }
        sc.close();
        
        //Second Pass
        
        Scanner sc2 = new Scanner(in);
        while(sc2.hasNextLine()) {
            String instruction = "";
            line = sc2.nextLine().trim();
            if(!line.isEmpty() && (line.charAt(0) == '/' || line.charAt(0) == '(')) {    //if it starts with a /, the whole thing is a comment
                line="";
            } else if(line.indexOf('/') != -1) {                    //gets rid of comments after statement
                line=line.substring(0,line.indexOf('/')-1);
            }
            if(!line.isEmpty()) {
                if(line.charAt(0) == '@') {                         //a-instruction
                    String symbol = line.substring(1);
                    int symbolnumber = findSymbol(symbolarray, symbol);             //Gets symbolpointer from symbolchart
                    String binarynum = Integer.toBinaryString(symbolnumber);        //converts to pointer to binary
                    instruction += "0";
                    while(instruction.length() + binarynum.length() < 16) {         //adds 0s in front of binary num
                        instruction += "0";
                    }
                    instruction += binarynum;
                } else {                                            //c-instruction
                    instruction += "111";
                    
                    //comp bits
                    String compins = line;
                    if(compins.indexOf('=') != -1) {    //it has an =
                        compins=compins.substring(compins.indexOf('=')+1);
                    }
                    if(compins.indexOf(';') != -1) {    //it has an ;
                        compins=compins.substring(0,compins.indexOf(';'));
                    }
                    //a bit
                    if(compins.indexOf('A') != -1) {        //it has an A
                        instruction += "0";
                    } else {                                //it doesn't have an A
                        instruction += "1";
                    }
                    //c bits
                    instruction += getcbits(compins);
                    
                    //dest bits
                    String destins = line;
                    if(destins.indexOf('=') != -1) {
                        destins=destins.substring(0,destins.indexOf('='));
                        if(destins.indexOf('A') !=-1) instruction += "1";
                        else instruction += "0";
                        
                        if(destins.indexOf('D') !=-1) instruction += "1";
                        else instruction += "0";
                        
                        if(destins.indexOf('M') !=-1) instruction += "1";
                        else instruction += "0";   
                    } else {
                        instruction += "000";
                    }
                    
                    //jmp bits
                    String jmpins = line;
                    if(jmpins.indexOf(';') != -1) {
                        jmpins = jmpins.substring(jmpins.indexOf(';')+1);
                        instruction += getjbits(jmpins);
                    } else {
                        instruction += "000";
                    }
                }
                writer.write(instruction);
                writer.newLine();
            }
        }
        sc2.close();
        writer.close();
    }
	
    //returns whether or not a symbolname is in the symbolarray.
    public static boolean isInArray(Symbol[] symbolarray, String symbolname) {
        for(int i=0;i<symbolarray.length;i++) {
            if(symbolarray[i] == null) return false;
            if(symbolarray[i].getSymbol().equals(symbolname)) return true;
        }
        return false;
    }
    //returns whether or not a string is a integer.
    public static boolean isInteger(String str) {
        if(str == null || str.trim().isEmpty()) {
            return false;
        }
        for (int i = 0; i < str.length(); i++) {
            if(!Character.isDigit(str.charAt(i))) {
                return false;
            } 
        }
        return true;
    }
    //returns the position of a symbolname in the symbol array or -1 if it isnt in the array.
    public static int findSymbol(Symbol[] symbolarray, String symbolname) {
        if(!isInArray(symbolarray, symbolname)) return -1;
        for(int i=0;i<symbolarray.length;i++) {
            if (symbolarray[i].getSymbol().equals(symbolname)) return i;
        }
        return -1;
    }
    public static String getcbits(String compins) {
        switch(compins) {
            case "0":   return "101010";
            case "1":   return "111111";
            case "-1":  return "111010";
            case "D":   return "001100";
            case "A":   return "110000";
            case "M":   return "110000";
            case "!D":  return "001101";
            case "!A":  return "110001";
            case "!M":  return "110001";
            case "-D":  return "001111";
            case "-A":  return "110011";
            case "-M":  return "110011";
            case "D+1": return "011111";
            case "A+1": return "110111";
            case "M+1": return "110111";
            case "D-1": return "001110";
            case "A-1": return "110010";
            case "M-1": return "110010";
            case "D+A": return "000010";
            case "D+M": return "000010";
            case "D-A": return "010011";
            case "D-M": return "010011";
            case "A-D": return "000111";
            case "M-D": return "000111";
            case "D&A": return "000000";
            case "D&M": return "000000";
            case "D|A": return "010101";
            case "D|M": return "010101";
        }
        return "";
    }
    public static String getjbits(String jmpins) {
        switch(jmpins) {
            case "JGT": return "001";
            case "JEQ": return "010";
            case "JGE": return "011";
            case "JLT": return "100";
            case "JNE": return "101";
            case "JLE": return "110";
            case "JMP": return "111";
        }
        return "";
    }
}