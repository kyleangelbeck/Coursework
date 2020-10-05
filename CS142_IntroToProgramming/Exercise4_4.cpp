#include <iostream>
using namespace std;
int eoo(int a);
int add(int b);
int main() {
	int n;
	cout<<"enter an integer"<<endl;
	cin>>n;
	if(eoo(n) == 1) {
		cout<<add(n)<<endl;
	} else {
		cout<<"You entered an odd number"<<endl;
	}
	return 0;
}
int eoo(int a) {
	if(a % 2 == 0) {
		return 1;
	} else {
		return 0;
	}
}
int add(int b) {
	int c;
	for(int i = 1; i < b; i++) {
		c += i;
	}
	return c;
}