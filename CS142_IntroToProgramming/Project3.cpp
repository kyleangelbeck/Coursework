/* Kyle Angelbeck
CS142-02
Project 3
October 5th, 2017 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void test(int);
void insult();
int main() {
	int randNum, playAgain;
	srand(time(NULL));
	do {
		randNum = rand()%100+1;
		test(randNum);
		cout<<"Type 1 to play again"<<endl;
		cin>>playAgain;
	} while (playAgain == 1);
	return 0;
}
void test(int ans) {
	int guess;
	do {
		cout<<"Enter your guess"<<endl;
		cin>>guess;
		if(guess == ans) {
			cout<<"Correct"<<endl;
		} else if(guess < ans)	{
			cout<<"Too low ";
			insult();
		} else {
			cout<<"Too high ";
			insult();
		}
	} while (guess != ans);
}
void insult() {
	int i = rand()%5+1;
	if (i == 1) {
		cout<<"dunce"<<endl;
	} else if(i == 2) {
		cout<<"cretin"<<endl;
	} else if(i == 3) {
		cout<<"cow"<<endl;
	} else if(i == 4) {
		cout<<"dipstick"<<endl;
	} else {
		cout<<"wanker"<<endl;
	}
}
/* Enter your guess
50
Too high cow
Enter your guess
25
Too high dipstick
Enter your guess
20
Too high dunce
Enter your guess
16
Correct
Type 1 to play again
0 */