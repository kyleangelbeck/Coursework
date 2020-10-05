//Greedy Algorithm for I/O Knapsack Problem
//With and Without Allowing Fractions
//Takes weight/benefit values from a txt file as input

import java.util.*;         
import java.util.Scanner;
import java.io.*;

class GreedyKnapsack {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new FileReader("Input.txt"));
        int num = input.nextInt();
        int maxWeight = input.nextInt();

        int weight, benefit, i;
        Item[] items = new Item[num];


        //input data
        for(int j = 0; j < num; j++) {
            int tempW = input.nextInt();
            int tempB = input.nextInt();
            items[j] = new Item(j+1,tempW,tempB);
        }
        Arrays.sort(items, Collections.reverseOrder());

        //Without Fractions
        i = 0;
        weight = maxWeight;
        benefit = 0;
        while(true) {
            if (items[i].getWeight() <= weight) {    //if it fits, add benefit and subtract weight
                benefit += items[i].getBenefit();
                weight -= items[i].getWeight();
                if(i == num-1)  break;               //check if last item
            } else {
                break;
            }
            i++;
        }
        System.out.println("Maximum benefit with no fractions is: " + benefit);

        //With Fractions
        i = 0;
        weight = maxWeight;
        benefit = 0;
        while(true) {
            if (items[i].getWeight() <= weight) {   //if it fits, add benefit and subtract weight
                benefit += items[i].getBenefit();
                weight -= items[i].getWeight();
                if(i == num-1)  break;              //check if last item
                if(weight == 0)  break;             //check if bag is full
            } else {
                benefit += (items[i].getRatio() * weight);
                weight = 0;
                break;
            }
            i++;
        }
        System.out.println("Maximum benefit with fractions is: " + benefit);
    }
}