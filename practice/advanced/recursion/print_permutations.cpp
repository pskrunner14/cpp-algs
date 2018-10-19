#include <iostream>
#include <cstring>
using namespace std;

void printPermutations(string input, string output=""){
	if (input.empty()) {
      	cout << output << endl;
      	return;
    }
  	for (int i = 0; i < input.size(); i++) {
      	string copy = input;
      	printPermutations(copy.erase(i, 1), output + input.substr(i, 1));
    }
}

int main(){
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}