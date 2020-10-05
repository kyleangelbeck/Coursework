//Backtracking Algorithm for I/O Knapsack Problem
//Takes weight/benefit values from a txt file as input

import java.util.*;         
import java.util.Scanner;
import java.io.*;

class BacktrackingKnapsack {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new FileReader("Input.txt"));
        int num = input.nextInt();
        int maxWeight = input.nextInt();
        Item[] items = new Item[num];

        int maxProfit = 0;
        int index = 0;


        //input data
        for(int i = 0; i < num; i++) {
            int tempW = input.nextInt();
            int tempB = input.nextInt();
            items[i] = new Item(i+1,tempW,tempB);
        }

        //root
        Node root = new Node();
        root.setBound(calculateBound(items, null, maxWeight));
        Node currentNode = root;
        Node bestNode;

        boolean done = false;
        while(!done) {
            if(promising(items, currentNode, maxWeight, maxProfit)) {
                //Create and change currentNode to child
                if(currentNode.getLeft()==null) {
                    currentNode.setLeft(new Node(currentNode));
                    currentNode = currentNode.getLeft();
                    currentNode.fillLeft(items, maxWeight);
                } else {
                    currentNode.setRight(new Node(currentNode));
                    currentNode = currentNode.getRight();
                    currentNode.fillRight(items);
                    currentNode.setBound(calculateBound(items, currentNode, maxWeight));
                }
                
                if(currentNode.getBenefit() > maxProfit && currentNode.getBound() != 0) {
                    maxProfit = currentNode.getBenefit();
                    bestNode = currentNode;
                }
                
                //print new node
                System.out.println(currentNode);

            } else {
                //traverse tree to find next right node
                currentNode = currentNode.getParent();
                while(currentNode.getRight()!=null) {
                    if(currentNode == root) {
                        done = true;
                        break;
                    }
                    currentNode = currentNode.getParent();
                }
            }
        }
        System.out.println(maxProfit);
    }

    public static int calculateBound(Item[] items, Node n, int maxWeight) {
        int w, i, p;

        //initialize variables
        if(n == null) {
            w = 0;
            i = 0;
            p = 0;
        } else {
            w = n.getWeight();
            p = n.getBenefit();
            i = n.getIndex();
        }

        //add profits that fit
        while(i<items.length && w+items[i].getWeight()<=maxWeight) {
            p += items[i].getBenefit();
            w += items[i].getWeight();
            i++;
        }

        //add fraction of last item
        if(i<items.length) {
            p += items[i].getRatio() * (maxWeight - w);
        }

        return p;
    }

    public static boolean promising(Item[] items, Node n, int maxWeight, int maxProfit) {
        return !(n.getWeight() >= maxWeight || n.getBound() < (double) maxProfit || n.getIndex()>=items.length);
    }
}