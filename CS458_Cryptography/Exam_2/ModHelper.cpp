// This is a helper program created to find x in 79x = 1 mod 157 and 61x = 79 mod 157 in Problem 1 Parts 2 and 4
// Kyle Angelbeck
#include <iostream> //cout
using namespace std;

int main() {
    int i = 0, mod = 0;
    while (i < 157 && mod != 1)  mod = (79*i++) % 157;
    cout<<"Part 2: x = "<<i-1<<endl;

    i=0;
    mod=0;
    while (i < 157 && mod != 79)  mod = (61*i++) % 157;
    cout<<"Part 4: x = "<<i-1<<endl;

    return 0;
}
