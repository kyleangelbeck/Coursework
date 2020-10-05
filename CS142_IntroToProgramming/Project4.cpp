/*
Kyle Angelbeck
CS142-02
This program takes in quiz/hw, test, and a final grade
and outputs a letter grade and percentage grade
*/
#include <iostream>
using namespace std;

void menu();
void hwAndQuiz(int &numq, int &qscore);
void exam(int &nume, int &escore);
void finalExam(int &fscore);
void grade(int &numq, int &qscore, int &nume, int &escore, int &fscore, bool &takef);

int main(){
	int menuPointer, numq = 0, qscore = 0, nume = 0, escore = 0, fscore = 0;
	bool takef = false;
	cout<<"*****Welcome to the grade checking program******"<<endl;
	do {		//chooses which function to run based off of the input
		menu();
		cin>>menuPointer;
		if(menuPointer == 1) {
			hwAndQuiz(numq, qscore);
		} else if(menuPointer == 2) {
			exam(nume, escore);
		} else if(menuPointer == 3) {
			finalExam(fscore);
			takef = true;
		} else if(menuPointer == 4) {
			grade(numq, qscore, nume, escore, fscore, takef);
		} else if(menuPointer == 5) {
			cout<<"Exiting..."<<endl;
		} else {
			cout<<"input a number 1-5"<<endl;
		}
	} while(menuPointer != 5);
}
//displays menu
void menu() {
	cout<<"Enter Your Score for each of the following:"<<endl;
	cout<<"1)	Homework or Quiz (10 point/each)"<<endl;
	cout<<"2)	Exam (50 points /each)"<<endl;
	cout<<"3)	Final Exam (100 points)"<<endl;
	cout<<"4)	Show grade"<<endl;
	cout<<"5)	Exit"<<endl;
}
//takes in any amount of quize/homework grades and displays the current total grade for this category.
void hwAndQuiz(int &numq, int &qscore) {
	int tempscore = 0, tempq = 0;
	if(numq == 0) {
		cout<<"How many homework and quiz grades do you have?   ";
	} else {
		cout<<"How many homework and quiz grades are you adding?   ";
	}
	cin>>tempq;
	numq += tempq;
	for(int i = 1; i <= tempq; i++) {
		cout<<"Enter your score for homework or quiz "<<i + numq - tempq<<": ";
		cin>>tempscore;
		if(tempscore > 10) {
			cout<<" Error: You cann't have "<<tempscore<<" points!"<<endl;
			i--;
		} else {
			qscore += tempscore;
		}
	}
	cout<<"Total quiz score: "<<qscore<<"/"<<numq*10<<endl;
}
//takes in any amount of exam grades and displays the current total grade for this category.
void exam(int &nume, int &escore) {
	int tempscore = 0, tempe = 0;
	if(nume == 0) {
		cout<<"How many exam grades do you have?   ";
	} else {
		cout<<"How many exam grades are you adding?   ";
	}
	cin>>tempe;
	nume += tempe;
	for(int i = 1; i <= tempe; i++) {
		cout<<"Enter your score for exam "<<i + nume - tempe<<": ";
		cin>>tempscore;
		if(tempscore > 50) {
			cout<<" Error: You cann't have "<<tempscore<<" points!"<<endl;
			i--;
		} else {
			escore += tempscore;
		}
	}
	cout<<"Total quiz score: "<<escore<<"/"<<nume*50<<endl;
}
//Takes in a final exam score
void finalExam(int &fscore) {
	int tempscore;
	cout<<"What was your grade on your final exam?   ";
	cin>>tempscore;
	if(tempscore > 100) {
		cout<<" Error: You cann't have "<<tempscore<<" points!"<<endl;
		finalExam(fscore);
	} else {
		fscore = tempscore;
	}
}
//Outputs the current letter grade, percentage grade, and a grade for each category.
void grade(int &numq, int &qscore, int &nume, int &escore, int &fscore, bool &takef) {
	int points, maxpoints;
	double percentgrade;
	if(takef) {
		maxpoints = numq * 10 + nume * 50 + 100;
		points = qscore + escore + fscore;
	} else {
		maxpoints = numq * 10 + nume * 50;
		points = qscore + escore;
	}
	percentgrade = 100.0*points/maxpoints;
	if(numq > 0) {
		cout<<"1) Homework and Quizes: "<<qscore<<"/"<<numq*10<<endl;
	} else {
		cout<<"1) No Homework or Quizes"<<endl;
	}
	if(nume > 0)	{
		cout<<"2) Exams: "<<escore<<"/"<<nume*50<<endl;
	} else {
		cout<<"2) No Exams"<<endl;
	}
	if(takef) {
		cout<<"3) Final Exam: "<<fscore<<"/100"<<endl;
	} else {
		cout<<"3) No Final Exam"<<endl;
	}
	cout<<"Grade percentage: "<<percentgrade<<"%"<<endl;
	if(percentgrade >= 92) {
		cout<<"Letter Grade: A"<<endl;
	} else if(percentgrade >= 85) {
		cout<<"Letter Grade: B"<<endl;
	} else if(percentgrade >= 70) {
		cout<<"Letter Grade: C"<<endl;
	} else if(percentgrade >= 60) {
		cout<<"Letter Grade: D"<<endl;
	} else {
		cout<<"Letter Grade: F"<<endl;
	}
}




/*
thomas% g++ Project4.cpp
thomas% a.out
*****Welcome to the grade checking program******
Enter Your Score for each of the following:
1)      Homework or Quiz (10 point/each)
2)      Exam (50 points /each)
3)      Final Exam (100 points)
4)      Show grade
5)      Exit
1
How many homework and quiz grades do you have?   2
Enter your score for homework or quiz 1: 9
Enter your score for homework or quiz 2: 7
Total quiz score: 16/20
Enter Your Score for each of the following:
1)      Homework or Quiz (10 point/each)
2)      Exam (50 points /each)
3)      Final Exam (100 points)
4)      Show grade
5)      Exit
2
How many exam grades do you have?   3
Enter your score for exam 1: 50
Enter your score for exam 2: 50
Enter your score for exam 3: 40
Total quiz score: 140/150
Enter Your Score for each of the following:
1)      Homework or Quiz (10 point/each)
2)      Exam (50 points /each)
3)      Final Exam (100 points)
4)      Show grade
5)      Exit
3
What was your grade on your final exam?   89
Enter Your Score for each of the following:
1)      Homework or Quiz (10 point/each)
2)      Exam (50 points /each)
3)      Final Exam (100 points)
4)      Show grade
5)      Exit
4
1) Homework and Quizes: 16/20
2) Exams: 140/150
3) Final Exam: 89/100
Grade percentage: 90.7407%
Letter Grade: B
Enter Your Score for each of the following:
1)      Homework or Quiz (10 point/each)
2)      Exam (50 points /each)
3)      Final Exam (100 points)
4)      Show grade
5)      Exit
5
Exiting...
*/