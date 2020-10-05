//Kyle Angelbeck
//CS142-02
//This program allows a user to save a student's record
//in a file and then displays the information given.
include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void input();
void output();

int main() {
	input();
	output();
	return 0;
}
void input() {
	char f[80];
	char l[80];
	int id, c, ce, grade;
	cout<<"Enter your first name."<<endl;
	cin.getline(f,80);
	cout<<"Enter your last name."<<endl;
	cin.getline(l,80);
	cout<<"Enter your ID number."<<endl;
	cin>>id;
	cout<<"Enter your credits."<<endl;
	cin>>c;
	cout<<"Enter your credits earned."<<endl;
	cin>>ce;
	cout<<"Enter your total grade points."<<endl;
	cin>>grade;
	ofstream outfile("Record.txt");
	outfile<<f<<" "<<l<<" "<<id<<" "<<c<<" "<<ce<<" "<<grade;
	outfile.close();
}
void output() {
	char f[80];
	char l[80];
	int id, c, ce, grade;
	ifstream infile("Record.txt");
	infile>>f>>l>>id>>c>>ce>>grade;
	infile.close();
	cout<<"First Name: "<<f<<"\t Last Name: "<<l<<"\t ID: "<<id<<endl;
	cout<<"Credits: "<<c<<"\t Credits Earned: "<<ce<<"\t Total grade points: "<<grade<<endl;
}
/*
thomas% a.out
Enter your first name.
Kyle
Enter your last name.
Angelbeck
Enter your ID number.
12345
Enter your credits.
15
Enter your credits earned.
14
Enter your total grade points.
555
First Name: Kyle         Last Name: Angelbeck    ID: 12345
Credits: 15      Credits Earned: 14      Total grade points: 555
*/