#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, t=0;
	cout<<"Enter an integer"<<endl;
	cin>>n;
	for(int i = 0; i <= n; i++) {
		t += pow(3,i);
	}
	cout<<t<<endl;
	return 0;
}