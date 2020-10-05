//import java.io.*;
import java.util.*;
class Project1NEW {
    public static void main(String [] args) {
        int count = 0;
        char charIn;
        String candy;
        boolean t = true;

        Scanner in = new Scanner(System.in);


        while(t) {
            System.out.println("Current cents inserted: " + count + "\nInput: ");
            charIn = in.next().charAt(0);

            if(charIn == 'n') {
                 if(count!= 30) count += 5;
            } else if(charIn == 'd') {
                if(count <= 20) count += 10;
                else count = 30;
            } else if(charIn == 'q') {
                if(count == 0) count = 25;
                else count = 30;
            } else if(charIn == 'b') {
                if(count < 30) System.out.println("Please insert more coins");
                else {
                    System.out.println("Choose a piece of candy");
                    candy = in.next();
                    System.out.println("Here is your " + candy);
                    t = false;
                }
            } else {
                System.out.println("ERROR: " + charIn + " is not a valid input.");
            }
        }
    }
}