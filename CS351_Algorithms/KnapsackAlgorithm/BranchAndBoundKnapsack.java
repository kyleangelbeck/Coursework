//Best First Branch and Bound Algorithm for I/O Knapsack Problem
//Takes weight/benefit values from a txt file as input

import java.util.*;         
import java.util.Scanner;
import java.io.*;

class BranchAndBoundKnapsack {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new FileReader("Input.txt"));
        int num = input.nextInt();
        int maxWeight = input.nextInt();
        Item[] items = new Item[num];

        int maxProfit = 0;

        //using prioqueue made in CS248
        PriorityQueue q = new PriorityQueue(50);

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
    
        //if promising, create child nodes.
        //no matter what, go to next child and update maxProfit
        boolean done = false;
        while(!done) {
            if(promising(items, currentNode, maxWeight, maxProfit)) {
                //Create children and add them to prioqueue
                currentNode.setLeft(new Node(currentNode));
                currentNode.getLeft().fillLeft(items, maxWeight);
                q.enqueue(currentNode.getLeft());

                currentNode.setRight(new Node(currentNode));
                currentNode.getRight().fillRight(items);
                currentNode.getRight().setBound(calculateBound(items, currentNode, maxWeight));
                q.enqueue(currentNode.getRight());
            }

            //Go to next in prioqueue
            if(!q.isEmpty()) {
                currentNode = q.dequeue();
                if(currentNode.getBenefit() > maxProfit && currentNode.getBound() != 0) {
                    maxProfit = currentNode.getBenefit();
                    bestNode = currentNode;
                }
            } else {
                done = true;
            }

            //print new node
            System.out.println(currentNode);

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