#include <iostream>
using namespace std;

string *keys = new string[10]{"", "", "abc", "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad_print(int nums, string output) {
    if (nums == 0) {
        cout << output << endl;
        return;
    }
    for (int i = 0; i < keys[nums % 10].size(); i++) {
        keypad_print(nums / 10, keys[nums % 10][i] + output);
    }
}

int main() {
    int nums;
    string output = "";
    cin >> nums;

    keypad_print(nums, output);
    return 0;
}