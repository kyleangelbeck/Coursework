import java.io.*;
import java.util.*;

class Project3 {
    public static void main(String [] args) throws FileNotFoundException {
        File file = new File("Project3.java");
        Scanner inputScanner = new Scanner(file);
        String input;
        int count = 0;

        while(inputScanner.hasNextLine()) {
            input = inputScanner.nextLine();
            for(int i=0; i<input.length(); i++) {
                if(input.charAt(i) == 'i')  count++;
            }
            System.out.println(input);
        }

        System.out.println("\n\nNumber of i's: " + count);
    }
}