import java.util.*;         
import java.util.Scanner;
import java.io.*;

class CacheManagement {
    public static void main(String[] args) throws IOException {
        int TLBhits = 0, TLBmisses = 0;
        TLB tlb = new TLB();
        PageTable pageTable = new PageTable();

        //inputs
        Scanner input = new Scanner(new FileReader("Input.txt"));
        int n = input.nextInt();
        int[] vpns = new int[n];
        for(int i=0; i<n; i++) {
            vpns[i] = input.nextInt();
        }

        //LRU
        for(int i=0; i<n; i++) {
            if(tlb.lookup(vpns[i])) {
                TLBhits++;
            } else {
                TLBmisses++;
                pte temp = pageTable.lookup(vpns[i]);
                tlb.LRUinsert(temp);
            }
        }
        System.out.println("Least Recently Used");
        output(TLBhits, TLBmisses);

        //FIFO
        TLBhits = 0;
        TLBmisses = 0;
        tlb = new TLB();
        for(int i=0; i<n; i++) {
            if(tlb.lookup(vpns[i])) {
                TLBhits++;
            } else {
                TLBmisses++;
                pte temp = pageTable.lookup(vpns[i]);
                tlb.FIFOinsert(temp);
            }
        }
        System.out.println("First In First Out");
        output(TLBhits, TLBmisses);

        //Random
        TLBhits = 0;
        TLBmisses = 0;
        tlb = new TLB();
        for(int i=0; i<n; i++) {
            if(tlb.lookup(vpns[i])) {
                TLBhits++;
            } else {
                TLBmisses++;
                pte temp = pageTable.lookup(vpns[i]);
                tlb.Randominsert(temp);
            }
        }
        System.out.println("Random");
        output(TLBhits, TLBmisses);

    }

    public static void output(int h, int m) {
        System.out.println("HITS: " + h);
        System.out.println("MISSES: " + m);
        System.out.println("HIT RATE: " + (double) h / (h+m));
        System.out.println("Effective Access Time: " + ((h * 20) + (m * 520)) + " microseconds");
    }
}