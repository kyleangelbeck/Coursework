/*
Kyle Angelbeck
CS142-02
This program keeps track of how much
candy has been obtained during Halloween
*/
#include <iostream>
using namespace std;

void eat(int candy[]);
void find(int candy[]);
void inv(int candy[]);
void types();
void menu();

int main() {
	char menuPointer;
	int candy[7]={0, 0, 0, 0, 0, 0, 0};
	cout<<"** Welcome to the Candy Database Program! **"<<endl;
	menu();
	do {
		cout<<"Command: ";
		cin>>menuPointer;
		if(menuPointer == 'E') {
			eat(candy);
		} else if(menuPointer == 'F') {
			find(candy);
		} else if(menuPointer == 'I') {
			inv(candy);
		} else if(menuPointer == 'C') {
			types();
		} else if(menuPointer == 'M') {
			menu();
		} else if(menuPointer == 'Q') {
			cout<<"Exiting..."<<endl;
		} else {
			cout<<"Not a valid command."<<endl;
		}
	} while(menuPointer != 'Q');
	return 0;
}
//decrements the type of candy you ate.
void eat(int candy[]) {
	if(candy[0] == 0) {
		cout<<"You do not have any candy."<<endl;
		return;
	}
	int n;
	cout<<"Please enter the candy type (1-6): ";
	cin>>n;
	if(n > 6 || n < 1) {
		cout<<"Error: That candy type doesn't exist."<<endl;
		eat(candy);
		return;
	}
	if(candy[n] <= 0) {
		cout<<"Error: You don't have any candy of that type."<<endl;
		return;
	}
	candy[n]--;
	candy[0]--;
}
//increments the type of candy you find
void find(int candy[]) {
	int n;
	cout<<"Please enter the candy type (1-6): ";
	cin>>n;
	if(n > 6 || n < 1) {
		cout<<"Error: That candy type doesn't exist."<<endl;
		find(candy);
		return;
	}
	candy[n]++;
	candy[0]++;
}
//displays amount of candy owned
void inv(int candy[]) {
	cout<<"Chocolate Eggs: "<<candy[1]<<endl;
	cout<<"Marshmallow Chicks: "<<candy[2]<<endl;
	cout<<"Snickers Bars: "<<candy[3]<<endl;
	cout<<"Peanutbutter Cups: "<<candy[4]<<endl;
	cout<<"M&Ms: "<<candy[5]<<endl;
	cout<<"Other: "<<candy[6]<<endl;
	cout<<"Total: "<<candy[0]<<endl;
}
//displays number codes for each type of candy
void types() {
	cout<<"1: Chocolate Eggs"<<endl;
	cout<<"2: Marshmallow Chicks"<<endl;
	cout<<"3: Snickers Bars"<<endl;
	cout<<"4: Peanutbutter Cups"<<endl;
	cout<<"5: M&Ms"<<endl;
	cout<<"6: Other"<<endl;
}
//displays lettered commands
void menu() {
	cout<<"E: Eat a piece of candy"<<endl;
	cout<<"F: Find a piece of candy"<<endl;
	cout<<"I: Inventory listing"<<endl;
	cout<<"C: List candy types"<<endl;
	cout<<"M: Print this menu of commands"<<endl;
	cout<<"Q: Quit this program"<<endl;
}
/*
thomas% a.out
** Welcome to the Candy Database Program! **
E: Eat a piece of candy
F: Find a piece of candy
I: Inventory listing
C: List candy types
M: Print this menu of commands
Q: Quit this program
Command: F
Please enter the candy type (1-6): 1
Command: F
Please enter the candy type (1-6): 1
Command: F
Please enter the candy type (1-6): 3
Command: F
Please enter the candy type (1-6): 5
Command: F
Please enter the candy type (1-6): 6
Command: F
Please enter the candy type (1-6): 5
Command: F
Please enter the candy type (1-6): 3
Command: E
Please enter the candy type (1-6): 3
Command: E
Please enter the candy type (1-6): 5
Command: E
Please enter the candy type (1-6): 6
Command: E
Please enter the candy type (1-6): 6
Error: You don't have any candy of that type.
Command: I
Chocolate Eggs: 2
Marshmallow Chicks: 0
Snickers Bars: 1
Peanutbutter Cups: 0
M&Ms: 1
Other: 0
Total: 4
Command: Q
Exiting...
*/