#include <cstring>
#include <iostream>
using namespace std;

// Add any helper functions(if needed) above.
char first_non_repeating(string str) {
    int* arr = new int[26];
    for (int i = 0; i < 26; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < str.size(); i++) {
        arr[str[i] - 'a'] += 1;
    }
    for (int i = 0; i < str.size(); i++) {
        if (arr[str[i] - 'a'] == 1)
            return str[i]; 
    }
    return '0';
}