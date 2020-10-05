//Dynamic Algorithm for I/O Knapsack Problem
//Takes weight/benefit values from a txt file as input

import java.util.*;         
import java.util.Scanner;
import java.io.*;

class DynamicKnapsack {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new FileReader("Input.txt"));
        int num = input.nextInt();
        int maxWeight = input.nextInt();
        Item[] items = new Item[num];

        int[][] arr = new int[num+1][maxWeight+1];


        //input data
        for(int i = 0; i < num; i++) {
            int tempW = input.nextInt();
            int tempB = input.nextInt();
            items[i] = new Item(i+1,tempW,tempB);
        }

        //Doesn't need to be sorted I think.
        //Arrays.sort(items, Collections.reverseOrder());

        for(int n = 0; n <= num; n++) {
            for(int w = 0; w <=maxWeight; w++) {
                if(w == 0 || n == 0) {                  //if at bottom or bag is full
                    arr[n][w] = 0;
                } else if(items[n-1].getWeight()<=w) {    //if item n fits
                    arr[n][w] = Math.max(arr[n-1][w-items[n-1].getWeight()] + items[n-1].getBenefit(), arr[n-1][w]);                    
                } else {
                    arr[n][w] = arr[n-1][w] ;            //if item n doesn't fit
                }
            }
        }
        
        System.out.println("Max benefit: " + arr[num][maxWeight]);
    }

    
}