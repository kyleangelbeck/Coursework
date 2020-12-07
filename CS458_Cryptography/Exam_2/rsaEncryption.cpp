// This is a helper program created to do simple rsa encryption for CS458 Exam 2 Question 6
// Takes two arguments, e and n, and allows the user to input messages as integers through
// the terminal and encrypts them using rsa with the given e and n.
// Usage: ./a.out e n
// Kyle Angelbeck

#include <iostream> //cin, cout
#include <string>   //string, stoi
#include <cctype>   //isdigit
using namespace std;

bool isnumber(string s) {
    bool b = true;

    for(int i=0; i < s.length(); i++) {
        if(!isdigit(s[i])) b = false;
    }

    return b;
}

int main(int argc, char* argv[]) {
    int e=atoi(argv[1]);
    int n=atoi(argv[2]);
    string sInput;

    cout << "Enter digits to encrypt" << endl;

    // Allow user to type as many messages as they want to be encrypted
    cin >> sInput;
    while(isnumber(sInput)) {
        int m = stoi(sInput);   // Message
        int c = m;              // Ciphertext
        
        // Modular exponentiation
        for(int i = e-1; i > 0; i--) {
            c = (c * m) % n;
        }

        cout << m << " -> " << c << endl;
        cin >> sInput;
    }


    return 0;
}
