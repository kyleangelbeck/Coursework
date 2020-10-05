#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double s;
	cout<<"Enter the side length of a square"<<endl;
	cin>>s;
	cout<<"the length of the diagonal of the square is "<<s * sqrt(2)<<endl;
	return 0;
}

/*
thomas% a.out
Enter the side length of a square
4
the length of the diagonal of the square is 5.65685
*/