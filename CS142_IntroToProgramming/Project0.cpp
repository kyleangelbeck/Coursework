//*********************************************************
// Program 0--The Welcome Program
// Author: Kyle Angelbeck	
//Date: August 31, 2017 
//Session 142-02
//This program asks the user his or her name, greets them by name, and
// welcomes them to CS142, the best course ever.
//
//***********************************************************

#include <iostream>
using namespace std;

int main()
{
   char name[30];
  
   cout<<"What is your name?  ";
   cin>> name;
   cout<<"Hello "<<name<<". "<<endl;
   cout<<"Welcome to CS142 !!!"<<endl;

  return 0;
}

/*
thomas% a.out
What is your name?  Kyle
Hello Kyle .
Welcome to CS142 !!!
*/