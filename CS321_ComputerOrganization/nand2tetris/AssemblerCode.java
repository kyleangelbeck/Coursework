import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class AssemblerCode	{
	public static void main(String[] args) throws FileNotFoundException {
		
		File in = new File("C:/Users/Kyle/Desktop/nand2tetris/projects/06/add/Add.asm");
		Scanner sc = new Scanner(in);
		Symbol[] symbolarray = new Symbol[8000];
		
		//First Pass
		int counter = 0;
		String line;
		int arraypos=0;
		int symbolcounter=16; //position of the pointer for the next variable symbol
		
		while(sc.hasNextLine()) {
			line = sc.nextLine().trim();
			if(line.charAt(0) == '/') line=null; //if it starts with a /, the whole thing is a comment
			if(line != null && line.indexOf('/') != -1) line=line.substring(0,line.indexOf('/')-1);	//gets rid of comments
			if(line != null && line.charAt(0) =='@') {
				String symbolname = line.substring(1); //gets rid of the @ at the beginning
				if(!isInArray(symbolarray,symbolname)) { //symbolname isnt in the table
					if(isInteger(symbolname)) { //isInteger is a selfmade function
						symbolarray[arraypos] = new Symbol(symbolname, Integer.parseInt(symbolname));
					} else {
						symbolarray[arraypos] = new Symbol(symbolname, -1);
					}
					arraypos++;
				}
			} else if(line != null && line.charAt(0) == '(') {
				String symbolname = line.substring(1,line.length()-2); //get rid of '(' at beginning and ')' at end
				if(!isInArray(symbolarray,symbolname)) { //symbolname isnt in the table
					symbolarray[arraypos] = new Symbol(symbolname, counter);
				} else {	//symbol name is in table, need to change the pointer
					symbolarray[findSymbol(symbolarray,symbolname)].updatePointer(counter);
				}
				arraypos++;
			}
			//counter increment
			if(line != null && line.charAt(0) != '(') counter++;
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
		/*
		sc = new Scanner(in);
		String[] instructions = new String[8000];		//array to hold all instructions
		while(sc.hasNextLine()) {
			line = sc.nextLine().trim();
			if(line.charAt(0) == '/' || line.charAt(0) == '(') line=null; //if it starts with a /, the whole thing is a comment
			if(line.indexOf('/') != -1) line=line.substring(0,line.indexOf('/')-1);	//gets rid of comments
			if(line!=null && line.charAt(0) == '@')
			
		}*/
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
}