#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

string get_code(string alpha) {
    char code = 'a' + stoi(alpha) - 1;
  	string s(1, code);
    return s;
}

void printAllPossibleCodes(string input, string output="") {
    if (input.empty()) {
      	cout << output << endl;
      	return;
    }
  	printAllPossibleCodes(input.substr(1), output + get_code(input.substr(0, 1)));
    if (input.size() >= 2 && 1 <= stoi(input.substr(0, 2)) && stoi(input.substr(0, 2)) <= 26) {
        printAllPossibleCodes(input.substr(2), output + get_code(input.substr(0, 2)));
    }
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}