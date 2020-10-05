/*
Kyle Angelbeck
CS142-02
August 14th, 2017

This program takes in the amount of credits that a person
is taking and outputs the cost of their tuition bill.
*/

#include <iostream>
using namespace std;

int main() {
	int c;
	while(c != -1) {
		cout<<"How many credits are yo taking? (-1 to exit)"<<endl;
		cin>>c;
		if(c == -1) {
			cout<<"Happy check writing!!"<<endl;
		} else if(c >= 0 && c <= 11) {
			cout<<"The tuition bill is $"<<c * 1310.00<<".00"<<endl;
		} else if(c >= 12 && c <= 20) {
			cout<<"The tuition bill is $15555.00"<<endl;
		} else if(c >= 21) {
			cout<<"The tuition bill is $"<<(c-20) * 1310.00 + 15555.00<<".00"<<endl;
		}
	}
	return 0;
}

/*
thomas% a.out
How many credits are yo taking? (-1 to exit)
9
The tuition bill is $11790.00
How many credits are yo taking? (-1 to exit)
15
The tuition bill is $15555.00
How many credits are yo taking? (-1 to exit)
22
The tuition bill is $18175.00
How many credits are yo taking? (-1 to exit)
-1
Happy check writing!!
thomas%
*/