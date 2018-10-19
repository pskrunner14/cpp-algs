#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// subsequences are all possible sequences/combinations
// that can be made from the characters in the string
//
// string with n chars -> 2^n subsequences

int subsequences(string str, string* output) {
    if (str.empty()) {
        output[0] = "";
        return 1;
    }
    int size = subsequences(str.substr(1), output);
    int i = 0;
    for (; i < size; i++)
        output[size + i] = str[0] + output[i];
    return size + i;
}

int main() {

    string str;
    getline(cin, str);

    int n = pow(2, str.size());

    string *output = new string[n];
    int size = subsequences(str, output);
    
    if (size != n)
        cout << "size mismatch" << endl;
    
    for (int i = 0; i < size; i++)
        cout << output[i] << endl;

    delete [] output;
    return 0;
}