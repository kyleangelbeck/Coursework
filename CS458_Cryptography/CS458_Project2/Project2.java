// Kyle Angelbeck, Paul Merkamp, and Nick Stitely's CS 458 Project 2: RSA Encryption

import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Project2 {
    public static void main(String[] args) throws IOException {
        Scanner cin = new Scanner(System.in);
        boolean running = true;

        String[] key = null;

        System.out.println("Welcome to RSA Encryption Program.");
        while (running) {
            printMenu();

            // Get user input
            String inputString = cin.nextLine();
            int inputInt;

            // Make sure user input is an integer
            try {
                inputInt = Integer.parseInt(inputString);
            } catch(NumberFormatException e) {
                System.out.println("ERROR: Invalid input. Enter a number.");
                continue;
            }

            System.out.println();

            // Do logic
            switch (inputInt) {
                case 1:
                    createPrivateKey(cin);
                    break;
                case 2:
                    createPublicKey(cin);
                    break;
                case 3:
                    // Array of size two indicates public, and size four indicates private
                    key = readKey(cin);
                    break;
                case 4:
                    // Make sure a key is loaded
                    if(key == null) {
                        System.out.println("ERROR: No key is loaded.");
                        break;
                    }

                    // Output to terminal
                    System.out.println(crypt(cin, key));
                    break;
                case 9:
                    running = false;
                    break;
                default:
                    System.out.println("Invalid Menu Choice");
            }
        }

        cin.close();
    }

    static void printMenu() {
        System.out.println("Enter a number");
        System.out.println("1: Create a private key, and save it to a 'mykey.privk'.");
        System.out.println("2: Create a public key from a private key, and save it to 'mykey.pubk'.");
        System.out.println("3: Load a public or private key.");
        System.out.println("4: Encrypt/decrypt a text file with the currently loaded key.");
        System.out.println("9: Exit Program");
    }

    // Create a public RSA key and store it in a specified file
    static void createPrivateKey(Scanner cin) throws IOException {
        // Ask user for number of digits for primes
        System.out.println("How many bits should the prime numbers p, q, and e be?");


        // Get user input
        String inputString = cin.nextLine();
        int primeSize;

        // Make sure user input is an integer
        try {
            primeSize = Integer.parseInt(inputString);
        } catch(NumberFormatException e) {
            System.out.println("ERROR: Invalid input. Enter a number.");
            return;
        }
        
        System.out.println("Creating Private Key...");

        // Generate private key
        // TODO: PrimeSize is in base 10, convert it to base 2. Currently creates a
        // prime with a bitSize of "primeSize"
        BigInteger p = BigInteger.probablePrime(primeSize, new Random());
        BigInteger q = BigInteger.probablePrime(primeSize, new Random());
        BigInteger n = p.multiply(q);
        BigInteger phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));

        BigInteger e = BigInteger.probablePrime(primeSize, new Random());
        // While gcd(e,phi) is not equal to 1...
        while (e.gcd(phi).compareTo(BigInteger.ONE) != 0) {
            e = BigInteger.probablePrime(primeSize, new Random());
        }
        BigInteger d = e.modInverse(phi);

        System.out.println("Public Key Created.\nSaving Private Key to mykey.privk...");

        // Create mykey.privk
        File outFile = new File("mykey.privk");
        if (outFile.exists()) {
            System.out.println("mykey.privk already exists, previous key will be overridden. Would you like to proceed?");
            System.out.println("'y' to proceed");
            char response = cin.nextLine().charAt(0);
            if (response != 'y') {
                System.out.println("The key has not been saved.");
                return;
            }
        }

        // Save space delimited n, d, p, and q to mykey.privk
        FileWriter fileWriter = new FileWriter(outFile);
        fileWriter.write(n.toString(36) + ' ');
        fileWriter.write(d.toString(36) + ' ');
        fileWriter.write(p.toString(36) + ' ');
        fileWriter.write(q.toString(36));
        fileWriter.close();
    }

    static void createPublicKey(Scanner cin) throws IOException {
        // Grab private key info from 'mykey.privk'
        File inFile = new File("mykey.privk");
        if (!inFile.exists()) {
            System.out.println("ERROR: No private key found.");
            return;
        }
        Scanner fileReader = new Scanner(new FileReader(inFile));
        BigInteger n = new BigInteger(fileReader.next(), 36);
        BigInteger d = new BigInteger(fileReader.next(), 36);
        BigInteger p = new BigInteger(fileReader.next(), 36);
        BigInteger q = new BigInteger(fileReader.next(), 36);

        // Calculate e
        BigInteger phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        BigInteger e = d.modInverse(phi);

        // Create mykey.pubk
        File outFile = new File("mykey.pubk");
        if (outFile.exists()) {
            System.out.println("mykey.pubk already exists, previous key will be overridden. Would you like to proceed?");
            System.out.println("'y' to proceed");
            char response = cin.nextLine().charAt(0);
            if (response != 'y') {
                System.out.println("The key has not been saved.");
                return;
            }
        }

        // Save space delimited n and e to mykey.pubk
        FileWriter fileWriter = new FileWriter(outFile);
        fileWriter.write(n.toString(36) + ' ');
        fileWriter.write(e.toString(36));
        fileWriter.close();
    }

    public static String[] readKey(Scanner cin) throws IOException {
        List<String> key = new ArrayList<String>();
        System.out.println("Would you like to read a public or private key?");
        String answer = cin.nextLine();
        if (answer.equalsIgnoreCase("private")) {
            // Handle key not existing
            try {
                key = readFile("mykey.privk");
            } catch(FileNotFoundException e) {
                System.out.println("ERROR: No private key found.");
                return null;
            }

            String[] priv = key.toString().replaceAll("[\\[\\](){}]", "").split("\\s");
            return priv;
        } else {
            // Handle key not existing
            try {
                key = readFile("mykey.pubk");
            } catch(FileNotFoundException e) {
                System.out.println("ERROR: No public key found");
                return null;
            }

            String[] pub = key.toString().replaceAll("[\\[\\](){}]", "").split("\\s");
            return pub;
        }
    }

    public static ArrayList<String> readFile(String filename) throws IOException {
        File file = new File(filename);
        Scanner reader;

        // Throw error up to who called this function
        try {
            reader = new Scanner(file);
        } catch(FileNotFoundException e) {
            throw e;
        }

        String line;
        ArrayList<String> lines = new ArrayList<String>();
        while (reader.hasNextLine()) {
            line = reader.nextLine();
            lines.add(line);
        }
        reader.close();
        return lines;
    }

    public static String crypt(Scanner cin, String[] key) throws IOException {
        // Get file name from user
        System.out.println("Enter filename to read from:");
        String filename = cin.nextLine();

        // in-file with each new line as a different String
        ArrayList<String> readIn;
        try {
            readIn = readFile(filename);
        } catch(FileNotFoundException e) {
            System.out.println("ERROR: file \"" + filename + "\" does not exist.");
            return "";
        }
        String toCrypt = "";

        if (key.length==2) {
            System.out.println("Currently loaded key is public. Encrypting...");

            int blockSize = key[0].length()-1;

            // Concatenate ArrayList and remove all punctuation
            String inputNoSpace = "";
            for(String s : readIn) {
                inputNoSpace += s;
            }
            inputNoSpace = inputNoSpace.replaceAll("[^a-zA-Z0-9]", "");

            // Insert a space in between each block
            for(int i=0; i<inputNoSpace.length(); i+=blockSize) {
                toCrypt += inputNoSpace.substring(i, Math.min(i+blockSize, inputNoSpace.length()));
                toCrypt += " ";
            }

        } else if (key.length==4) {
            System.out.println("Currently loaded key is private. Decrypting...");

            // Encrypted messages should be properly blocked, and have no punctuation
            for(String s : readIn) {
                toCrypt += s;
            }
        }

        // en/decrypt
        String crypted = "";
        for(String s : toCrypt.split(" ")) {
            crypted += cryptRSA(s,key);
            crypted += " ";
        }

        return crypted;
    }

    public static String cryptRSA(String s, String[] key){
        BigInteger a = new BigInteger(key[1], 36);
        BigInteger b = new BigInteger(key[0], 36);
        BigInteger m = new BigInteger(s, 36);
        return m.modPow(a,b).toString(36);
    }
}
