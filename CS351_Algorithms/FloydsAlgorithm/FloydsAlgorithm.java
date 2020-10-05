//Floyd's Algorithm for finding shortest path in a graph
//Takes a distance matrix from a txt file as its input

import java.lang.Math;      //Math.min()
import java.util.Scanner;   //Scanner()
import java.io.*;           //FileReader()

class FloydsAlgorithm {
    public static void main(String [] args) throws IOException {
        Scanner input = new Scanner(new FileReader("Input.txt"));

        int n = input.nextInt();
        double[][][] matricies = new double[n+1][n][n];
        int[][] P = new int[n][n];

        System.out.println("Matrix 0:");
        for(int row=0; row<n; row++) {      //fill matrix 0
            for(int col=0; col<n; col++) {
                double temp = input.nextInt();
                if(temp == -1) {
                    matricies[0][row][col] = Double.POSITIVE_INFINITY;
                    System.out.print("∞ ");
                } else {
                    matricies[0][row][col] = temp;
                    System.out.print((int) matricies[0][row][col] + " ");
                }
            }
            System.out.println();
        }

        for(int i=1; i<n+1; i++) {              //loop to fill each of the matricies
        System.out.println("\n\nMatrix " + i + ":");
            for(int row=0; row<n; row++) {      //fill matrix j
                for(int col=0; col<n; col++) { 
                    matricies[i][row][col] = Math.min(matricies[i-1][row][col], matricies[i-1][row][i-1] + matricies[i-1][i-1][col]);
                    if(matricies[i][row][col] != matricies[i-1][row][col]) P[row][col]=i;   //fill P
                    if(matricies[i][row][col] == Double.POSITIVE_INFINITY) {
                        System.out.print("∞ ");
                    } else {
                        System.out.print((int) matricies[i][row][col] + " ");
                    }
                }
                System.out.println();
            }
        }

        //print P
        System.out.println("\n\nMatric P:");
        for(int row=0; row<n; row++) {      //fill matrix j
            for(int col=0; col<n; col++) {
                System.out.print(P[row][col] + " ");
            }
            System.out.println();
        }
    }
}