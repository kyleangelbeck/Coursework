// This is a helper program created for CS458 Exam 1
// Kyle Angelbeck

#include<iostream>
using namespace std;

// ./a.out "column number" "keyword length" < "input file" > "output file"
// ./a.out 0 5 < temp.txt > c0.txt

int main(int argc, char* argv[]) {
    // First argument is the column number
    // Second argument is the keyword length
    int col=atoi(argv[1]);
    int k=atoi(argv[2]);

    int i=0;
    while(!cin.eof()) {
        char x = cin.get();
        if('a'<=x && x<='z') {
            if(i%k==col) cout << x;
            i++;
        }
        if('A'<=x && x<='Z') {
            if(i%k==col) cout << x;
            i++;
        }
    }
    return 0;
}
