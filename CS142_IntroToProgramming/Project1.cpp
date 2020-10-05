//Kyle Angelbeck
//CS142-02
//September 7th, 2017
//This program converts degrees fahrenheit into degrees centigrade.

#include <iostream> 
using namespace std;

int main() {
   double f, c;
   cout<<"Enter the temperature"<<endl;
   cin>>f;
   c=(f-32)*(5.0/9.0);
   cout<<f<<" degrees fahrenheit is equal to "<<c<<" degrees centigrade."<<endl;
   if(f<20) {
	   cout<<"It is cold outside."<<endl;
   } else if(f>85) {
	   cout<<"It is hot outside."<<endl;
   }
   return 0; 
}

/*
thomas% a.out
Enter the temperature
100
100 degrees fahrenheit is equal to 37.7778 degrees centigrade.
It is hot outside.
*/