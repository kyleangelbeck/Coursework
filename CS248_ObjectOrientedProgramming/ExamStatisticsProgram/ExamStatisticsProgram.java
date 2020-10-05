/** @author Kyle Angelbeck
Assignment 2*/
import java.io.*;
import java.util.*;

class ExamStatisticsProgram {
	public static void main(String [] args) throws IOException {
		Scanner cin = new Scanner(System.in);
		System.out.print("Enter the name of the file: ");
		String name = cin.nextLine();
		Scanner in = new Scanner(new FileReader(name));
		int n = in.nextInt();
		int[] scores = new int[n];
		for(int i = 0; i < scores.length; i++) {
			scores[i]=in.nextInt();
		}
		minmaxavg(scores);
		letterGrades(scores);
		System.out.println("There are "+scores.length+" Scores.");
		median(scores);
		in.close();
	}
	/** @param scores array of all scores */
	/** prints the minimum, maximum, and average scores */
	static void minmaxavg(int[] scores) {
		int min = scores[0], max = scores[0], total = 0;
		for(int i = 0; i < scores.length; i++) {
			if(scores[i] < min) {
				min = scores[i];
			} else if(scores[i] > max) {
				max = scores[i];
			}
			total += scores[i];
		}
		System.out.println("Minimum score: " + min);
		System.out.println("Maximum score: " + max);
		System.out.println("Average score: " + (total/scores.length));
	}
	/** @param scores array of all scores */
	/** prints amount of each letter grade recieved */
	static void letterGrades(int[] scores) {
		int a=0,b=0,c=0,d=0,f=0;
		for(int i = 0; i < scores.length; i++) {
			if(scores[i] >= 90) {
				a++;
			} else if(scores[i] >= 80) {
				b++;
			} else if(scores[i] >= 70) {
				c++;
			} else if(scores[i] >= 60) {
				d++;
			} else {
				f++;
			}
		}
		System.out.println("Number of scores by letter grade:");
		System.out.println("A; " + a);
		System.out.println("B: " + b);
		System.out.println("C: " + c);
		System.out.println("D: " + d);
		System.out.println("F: " + f);
	}
	/** @param scores array of all scores */
	/** prints median score */
	static void median(int[] scores) {
		Arrays.sort(scores);
		if(scores.length % 2 == 1) {
			System.out.println("median: " + scores[scores.length/2]);
		} else {
			System.out.println("median: " + (scores[scores.length/2-1] + scores[scores.length/2])/2.0);
		}
	}
}

/*
Enter the name of the file: esp.txt
Minimum score: 57
Maximum score: 100
Average score: 88
Number of scores by letter grade:
A; 4
B: 2
C: 0
D: 0
F: 1
There are 7 Scores.
median: 90
*/