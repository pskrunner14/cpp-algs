#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main() {

    unsigned int N, length, charNum, sumEven = 0, sumOdd = 0;
    ostringstream str1;
    string num;

    cin >> N;
    str1 << N;
    num = str1.str();
    length = num.size();

    char cstr[length + 1];
    strcpy(cstr, num.c_str());

    for (int i = 0; i < length; i++) {
        charNum = cstr[i] - '0';
        if (charNum % 2 == 0)
            sumEven += charNum;
        else 
            sumOdd += charNum;
    }

    cout << sumEven << " " << sumOdd << endl;
    return 0;
}