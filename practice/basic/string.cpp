#include <iostream>
using namespace std;

int length(char arr[]) {
    int len = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        len++;
    }
    return len;
}

int main() {

    char name[100]; // special behaviour
    char input[100];
    char delim_input[100];

    cin.getline(input, 100);
    cin.getline(delim_input, 100, 'x'); // x is delimiter
    // cin only takes input till space, tab or newline
    cin >> name; // ends with \0 (null char - ascii 0) [terminator]

    cout << input << endl;
    cout << name << endl; // reads till null char

    name[5] = '\0';
    cout << name << endl;

    cout << length(name) << endl;
    return 0;
}