import java.io.*;
import java.util.*;
// Kyle Angelbeck, Paul Merkamp, and Nick Stitely's CS 458 Project 1: Classical Encryption

class Project1 {
    public static void main(String[] args) throws IOException {
        // Get inputs from user
        Scanner cin = new Scanner(System.in);
        String inFile = getInFile(cin);
        char specifier = getSpecifier(cin);
        char alg = getAlg(cin);
        String key = getKey(cin);
        String outFile = getOutFile(cin);
        cin.close();
        
        // Run algorithm
        switch(alg) {
            case 'a':
                shiftCipher(inFile, outFile, key, specifier);
                break;
            case 'b':
                substitutionCipher(inFile, outFile, key, specifier);
                break;
            case 'c':
                affineCipher(inFile, outFile, key, specifier);
                break;
            case 'd':
                vigenereCipher(inFile, outFile, key, specifier);
                break;
            default:
                // Should never be reached
                System.out.println("ERROR: Invalid algorithm specifier");
                System.exit(1);
        }
    }

    // Return the input text file name. Received from the user.
    static String getInFile(Scanner cin) {
        System.out.print("Enter the name of the input file: ");
        String inFile = cin.nextLine();

        File f = new File(inFile);

        if(!f.exists()) {
            System.out.println("ERROR: file \"" + inFile + "\" does not exists.");
            System.exit(1);
        }

        return inFile;
    }

    // Return the character specifying whether the text should be encrypted or decrypted. Received from the user.
    static char getSpecifier(Scanner cin) {
        System.out.println("Would you like to (e)ncrypt or (d)ecrypt the text?");
        char specifier = cin.nextLine().charAt(0);
        if(specifier != 'e' && specifier != 'd') {
            System.out.println("ERROR: Invalid Input");
            System.exit(1);
        }
        return specifier;
    }

    // Return the character specifying which cipher algorithm should be used. Received from the user.
    static char getAlg(Scanner cin) {
        System.out.println("Which encryption algorithm should be run?");
        System.out.println("\ta: Shift Cipher");
        System.out.println("\tb: Substitution Cipher");
        System.out.println("\tc: Affine Cipher");
        System.out.println("\td: Vigenere Cipher");

        char alg = cin.nextLine().charAt(0);
        if(alg != 'a' && alg != 'b' && alg != 'c' && alg != 'd') {
            System.out.println("ERROR: Invalid Input");
            System.exit(1);
        }

        return alg;
    }

    // Return the key to the cipher algorithm. Received from the user.
    static String getKey(Scanner cin) {
        System.out.print("Enter the key to the cipher: ");
        return cin.nextLine();
    }

    // Return the output text file name. Received from the user.
    static String getOutFile(Scanner cin) throws IOException {
        System.out.print("Enter the name of the output file: ");
        String outFile = cin.nextLine();
        
        if(!outFile.endsWith(".txt")) {
            System.out.println("Please enter a .txt file as the output file.");
            System.exit(1);
        } else {
            createFile(cin, outFile);
        }

        return outFile;
    }

    // Creates new file to be written to.
    static void createFile(Scanner cin, String fileName) throws IOException {
        File newFile = new File(fileName);
        if(newFile.createNewFile()) {
            System.out.println("Output file has been created");
        } else {
            System.out.println("Output file already exists, previous contents will be overridden. Would you like to proceed?");
            System.out.println("'y' to proceed");
            char response = cin.nextLine().charAt(0);
            if(response == 'y') {
                newFile.delete();
                newFile.createNewFile();
            } else {
                System.out.println("Exiting Program...");
                System.exit(0);
            }
        }
    }

    // Takes in a string and a key
    // Returns an encrypted string using the shift cipher
    static void shiftCipher(String inFile, String outFile, String key, char specifier) throws IOException {
        // Make sure key is valid
        if(!Character.isLetter(key.charAt(0))) {
            System.out.println("ERROR: Invalid Key");
            System.exit(1);
        }

        Scanner fileReader = new Scanner(new FileReader(inFile));
        // FileWriter will append text to end of file
        FileWriter fileWriter = new FileWriter(outFile, true);

        String outText = "";
        String inText = "";

        while(fileReader.hasNextLine()) {
            inText = fileReader.nextLine();
            // Shift each character and append it to outText
            for(int i=0; i<inText.length(); i++) {
                outText += specifier == 'e'
                    ? shiftForward(inText.charAt(i), key.charAt(0))
                    : shiftBack(inText.charAt(i), key.charAt(0));
            }
            fileWriter.write(outText);
        }

        // Close file streams
        fileReader.close();
        fileWriter.close();
    }

    // Shifts an input character forward by an inputted key
    static char shiftForward(char c, char key) {
        // If c is not a letter, return c
        if(!Character.isLetter(c)) {
            return c;
        }

        char temp = (char) (c + getShiftValue(key));
        // If temp is a correctly cased letter, return it. Otherwise add 26 to wrap around.
        if(Character.isUpperCase(c)){
            return Character.isUpperCase(temp)
                ? temp
                : (char) (temp - 26);
        } else {
            return Character.isLowerCase(temp)
                ? temp
                : (char) (temp - 26);
        }
}

    // Shifts an input character backward by an inputted key
    static char shiftBack(char c, char key) {
        // If c is not a letter, return c
        if(!Character.isLetter(c)) {
            return c;
        }

        char temp = (char) (c - getShiftValue(key));
        // If temp is a correctly cased letter, return it. Otherwise add 26 to wrap around.
        if(Character.isUpperCase(c)){
            return Character.isUpperCase(temp)
                ? temp
                : (char) (temp + 26);
        } else {
            return Character.isLowerCase(temp)
                ? temp
                : (char) (temp + 26);
        }
    }


    static void substitutionCipher(String inFile, String outFile, String key, char specifier) throws IOException {
        if (specifier=='e'){
            Scanner fileReader = new Scanner(new FileReader(inFile));
            // FileWriter will append text to end of file
            FileWriter fileWriter = new FileWriter(outFile, true);

            key = key.toUpperCase();
            ArrayList<Character> alphaset = new ArrayList<Character>();
            for (char c: "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray()){
                alphaset.add(c);
            }

            // reorder alphaset to begin with the last letter of the key
            char[] keyAsChars = key.toCharArray();
            char charToShiftTo = keyAsChars[keyAsChars.length-1];
            Character currentChar = 'A';
            while (currentChar!=charToShiftTo){
                alphaset.add(currentChar);
                alphaset.remove(0);
                currentChar=alphaset.get(0);
            }

            // reorder alphaset to have the key at the beginning
            for (char c: keyAsChars){
                alphaset.remove((Character) c);
            }
            for (int i=keyAsChars.length-1; i>=0; i--){
                alphaset.add(0, keyAsChars[i]);
            }

            while(fileReader.hasNextLine()) {
                String inText = fileReader.nextLine();
                // read inText, remove spaces, make all caps
                inText.toUpperCase();

                ArrayList<Character> outTextAsChars = new ArrayList<Character>();
                for (char d : inText.toCharArray()) {
                    if (d == ' ') 
                        outTextAsChars.add(' ');
                    else
                        outTextAsChars.add(alphaset.get(getShiftValue(d)));
                }

                String outText = "";
                for (char d : outTextAsChars){
                    outText += d;
                }

                fileWriter.write(outText + '\n');
            }

            // Close file streams
            fileReader.close();
            fileWriter.close();
            
        }
        else if (specifier=='d'){
            Scanner fileReader = new Scanner(new FileReader(inFile));
            // FileWriter will append text to end of file
            FileWriter fileWriter = new FileWriter(outFile, true);

            key = key.toUpperCase();
            ArrayList<Character> alphaset = new ArrayList<Character>();
            for (char c: "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray()){
                alphaset.add(c);
            }
            ArrayList<Character> codedset = new ArrayList<Character>();
            for (char d: alphaset){
                codedset.add(d);
            }

            // reorder alphaset to begin with the last letter of the key
            char[] keyAsChars = key.toCharArray();
            char charToShiftTo = keyAsChars[keyAsChars.length-1];
            Character currentChar = 'A';
            while (currentChar!=charToShiftTo){
                codedset.add(currentChar);
                codedset.remove(0);
                currentChar=codedset.get(0);
            }

            // reorder alphaset to have the key at the beginning
            for (char e: keyAsChars){
                codedset.remove((Character) e);
            }
            for (int i=keyAsChars.length-1; i>=0; i--){
                codedset.add(0, keyAsChars[i]);
            }

            // now that the keyed alphabet has been generated, decode the inFile
            while(fileReader.hasNextLine()) {
                String inText = fileReader.nextLine();
                // read inText, remove spaces, make all caps
                inText.toUpperCase();

                ArrayList<Character> outTextAsChars = new ArrayList<Character>();
                for (char f : inText.toCharArray()) {
                    if (f != ' ') {
                        outTextAsChars.add(alphaset.get(codedset.indexOf(f)));  
                    }
                    else
                        outTextAsChars.add(' ');
                }

                String outText = "";
                for (char g : outTextAsChars){
                    outText += g;
                }
                outText = outText.toLowerCase();
                fileWriter.write((outText + '\n'));
            }

            // Close file streams
            fileReader.close();
            fileWriter.close();
        }
    }

    static void affineCipher(String inFile, String outFile, String key, char specifier) throws IOException {
        Scanner fileReader = new Scanner(new FileReader(inFile));
        // FileWriter will append text to end of file
        FileWriter fileWriter = new FileWriter(outFile, true);
        String text = "";
		
        // TO DO:
		
		// read in the input file
		while(fileReader.hasNextLine())
			text += fileReader.nextLine() + "\n";
        text = text.toLowerCase();
        
        // break the key into a string and an integer components
        String [] split = key.split("\\s");
        char k = split[0].charAt(0);
        int shift = getShiftValue(k);
        char j = split[1].charAt(0);
        int a = getShiftValue(j);

		// check for encryption or decryption
		if(specifier == 'e')
			text = eAff(text, shift, a);
		else
			text = dAff(text, shift, a);
		
		// write to the output file
        fileWriter.write(text);
		
        // Close file streams
        fileReader.close();
        fileWriter.close();
    }
	
	// helper function to encypt affine cipher
	static public String eAff(String input, int shift, int a)
	{
		// get the value of the key
		char [] cinput = input.toCharArray(); // input saved as charr array
		int i = 0;
		while(i < input.length())
		{
			int currentLetter = (int)cinput[i];
			if(currentLetter < 97 || currentLetter > 122)
				i++;
			else
			{
                if((char)(97 + (a*(getShiftValue(cinput[i])) + shift) % 26) > 122)
					cinput[i] = (char)((97 + (a*(getShiftValue(cinput[i])) + shift) % 26) + 26);
				else
					cinput[i] = (char)(97 + (a*(getShiftValue(cinput[i])) + shift) % 26);
				i++;
			}
		}
		input = new String(cinput);
		return input.toUpperCase().trim();
	}
	
	// helper function to decrypt affine cipher
	static public String dAff(String input, int shift, int a)
	{
		// get the value of the key
		char [] cinput = input.toCharArray(); // input saved as charr array
        int i = 0;

        // calculate a inverse
        a = inverse(a);
		while(i < input.length())
		{
			int currentLetter = (int)cinput[i];
			if(currentLetter < 97 || currentLetter > 122)
				i++;
			else
			{
                if((char)(97 + (a*(getShiftValue(cinput[i]) - shift)) % 26) < 97)
					cinput[i] = (char)((97 + (a*(getShiftValue(cinput[i]) - shift)) % 26) + 26);
				else
					cinput[i] = (char)(97 + (a*(getShiftValue(cinput[i]) - shift)) % 26);
				i++;
			}
		}
		input = new String(cinput);
		return input.trim();
    }
    
    // helper function to get inverse of number
    static int inverse(int a)
    {   int i;
        for (i = 1; i < 27; i++)
            if(((a * i) % 26) == 1)
                break;
        return i;
    }
    static void vigenereCipher(String inFile, String outFile, String key, char specifier) throws IOException {
        Scanner fileReader = new Scanner(new FileReader(inFile));
        // FileWriter will append text to end of file
        FileWriter fileWriter = new FileWriter(outFile, true);

        String text = "";
        
		// TO DO:
        
		// read in the input file
		while(fileReader.hasNextLine())
			text += fileReader.nextLine() + "\n";
		text = text.toLowerCase();
		
		// print out the input 
		//System.out.println(text);
		
		// check for encryption or decryption
		if(specifier == 'e')
			text = eVig(text, key);
		else
			text = dVig(text, key);
		
		// write to the output file
        fileWriter.write(text);
		
        // Close file streams
        fileReader.close();
        fileWriter.close();
    }
	
	// helper function to encypt vigenere cipher
	static public String eVig(String input, String key)
	{
		// break the key into a char array
		char [] ckey = key.toCharArray(); // key saved as char array
		char [] cinput = input.toCharArray(); // input saved as charr array
		int letter = 97;
		int i = 0;
		int k = 0;
		while(i < input.length())
		{
			int currentLetter = (int)cinput[i];
			if(currentLetter < 97 || currentLetter > 122)
				i++;
			else
			{
				if(k == key.length()-1)
				{
					int shift = getShiftValue(ckey[k]);					
					if(currentLetter + shift > 122)
					{
						letter = currentLetter + shift - 26;
						cinput[i] = (char)letter;
					}
					else
						cinput[i] = (char)(currentLetter + shift);
					k = 0;
				}
				else
				{
					int shift = getShiftValue(ckey[k]);
					if(currentLetter + shift > 122)
					{
						letter = currentLetter + shift - 26;
						cinput[i] = (char)letter;
					}
					else
						cinput[i] = (char)(currentLetter + shift);
					k++;
				}
				
				i++;
			}
		}
		
		// save the encrypted char array as a string
		input = new String(cinput);
		
		// return the string
		return input.toUpperCase().trim();
	}
	// helper function to decrypt vigenere cipher
	static public String dVig(String input, String key)
	{
		// break the key into a char array
		char [] ckey = key.toCharArray(); // key saved as char array
		char [] cinput = input.toCharArray(); // input saved as charr array
		int letter = 97;
		int i = 0;
		int k = 0;
		while(i < input.length())
		{
			int currentLetter = (int)cinput[i];
			if(currentLetter < 97 || currentLetter > 122)
				i++;
			else
			{
				if(k == key.length()-1)
				{
					int shift = getShiftValue(ckey[k]);
					if(currentLetter - shift < 97)
					{
						letter = currentLetter - shift + 26;
						cinput[i] = (char)letter;
					}
					else
						cinput[i] = (char)(currentLetter - shift);
					k = 0;
				}
				else
				{
					int shift = getShiftValue(ckey[k]);
					if(currentLetter - shift < 97)
					{
						letter = currentLetter - shift + 26;
						cinput[i] = (char)letter;
					}
					else
						cinput[i] = (char)(currentLetter - shift);
					k++;
				}
				
				i++;
			}
		}
		
		// save the encrypted char array as a string
		input = new String(cinput);
		
		// return the strings
		return input.trim();
	}

    // Returns the value of a character as an int
    // 'a': 0, 'b': 1, etc...
    static int getShiftValue(char c) {
        // This should never receive a non-letter
        if(!Character.isLetter(c)) return c;
        return Character.isLowerCase(c)
            ? c - 'a'
            : c - 'A';
    }
}
