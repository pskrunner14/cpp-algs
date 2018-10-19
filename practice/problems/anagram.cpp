#include <cstring>
#include <iostream>
using namespace std;

// Add any helper functions(if needed) above.
bool is_anagram(string input1, string input2) {
    int *arr  = new int[26];
    for (int i = 0; i < 26; i++)
        arr[i] = 0;
    for (int i = 0; i < input1.size(); i++)
        arr[input1[i] - 97] += 1;
    for (int i = 0; i < input2.size(); i++) {
        if (arr[input2[i] - 97] == 0)
            return false;
        else
            arr[input2[i] - 97] -= 1;
    }
    return true;
}