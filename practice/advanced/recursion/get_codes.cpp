#include <iostream>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

string get_code(string alpha) {
    char code = 'a' + stoi(alpha) - 1;
  	string s(1, code);
    return s;
}

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
  	if (input.empty()) {
      	output[0] = "";
      	return 1;
    }
  	string out1[1000];
  	int size1 = getCodes(input.substr(1), out1);
    for (int i = 0; i < size1; i++) {
    	output[i] = get_code(input.substr(0, 1)) + out1[i];
    }
    if (input.size() >= 2 && 1 <= stoi(input.substr(0, 2)) <= 26) {
        string out2[1000];
        int size2 = getCodes(input.substr(2), out2);
        for (int i = 0; i < size2; i++) {
            output[size1 + i] = get_code(input.substr(0, 2)) + out2[i];
        }
        size1 += size2;
    }
  	return size1;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}