#include <iostream>
#include <cstring>
using namespace std;

void replacePi(char input[]) {
	// Write your code here
	if (input[0] == '\0')
      	return;
  	if (input[0] == 'p' && input[1] == 'i') {
      	input[strlen(input) + 2] = '\0';
     	for (int i = strlen(input) + 1; i > 3; i--) {
          	input[i] = input[i - 2];
        }
      	input[0] = '3';
        input[1] = '.';
        input[2] = '1';
      	input[3] = '4';
      	return replacePi(input + 4);
    }
    return replacePi(input + 1);
}

int main() {
    char str[100];
    cin >> str;
    replacePi(str);
    cout << str << endl;
    return 0;
}