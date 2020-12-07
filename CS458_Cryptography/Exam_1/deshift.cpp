// This is a helper program created for CS458 Exam 1
// Kyle Angelbeck

#include<iostream>
using namespace std;

double english[]={
    674061888,
    70195826,
    138416451,
    169330528,
    95422055,
    91258980,
    216768975,
    320410057,
    9613410,
    35373464,
    183996130,
    110504544,
    313720540,
    326627740,
    90376747,
    4550166,
    277000841,
    294300210,
    390965105,
    117295780,
    46337161,
    79843664,
    8369915,
    75294515,
    4975847
};

// Converts english array to be frequencies rather than letter counts
void fixenglish() {
    double total=0;
    for(int i=0; i<26; i++) total += english[i];
    for(int i=0; i<26; i++) english[i] /= total;
}

// Computes the dotproduct of two double arrays
double dotproduct(double a[], double b[]) {
    double sum=0;
    for(int i=0; i<26; i++) sum += a[i]*b[i];
    return sum;
}

// Shifts the values of a double array to the right
void shift(double f[]) {
    double temp = f[0];
    for(int i=0; i<25; i++){
        f[i]=f[i+1];
    }
    f[25]=temp;
}

int main() {
    int counts[26] = {0};
    double freq[26] = {0};
    int total = 0;

    fixenglish();

    // Count frequency of letters of input
    while(!cin.eof()) {
        char x=cin.get();
        if('a'<=x && x<='z') {
            counts[x-(int)'a']++;
            total++;
        }
        if('A'<=x && x<='Z') {
            counts[x-(int)'A']++;
            total++;
        }
    }

    // Convert counts to frequencies
    for(int i=0; i<26; i++) freq[i]=(1.0*counts[i])/total;

    // Shift the frequencies array and calculate the dot product to get the index of coincidence
    double max=0;
    int maxshift=0;
    for(int shiftAmount=0; shiftAmount<26;  shiftAmount++) {
        if(max<dotproduct(freq,english)) {
            max=dotproduct(freq,english);
            maxshift = shiftAmount;
        }
        cout << char('A'+shiftAmount) << ": " << dotproduct(freq,english) << endl;
        shift(english);
    }

    cout << "The decryption key is: " << char('A'+maxshift) << endl;
    cout << "The dot product was: " << max << endl;

    return 0;
}
