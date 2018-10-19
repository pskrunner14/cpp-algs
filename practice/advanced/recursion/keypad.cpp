#include <iostream>
using namespace std;

string *keys = new string[10]{"", "", "abc", "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypad(string nums, string* output) {
    if (nums.size() == 1) {
        int num = nums[0] - '0';
        string str = keys[num];
        for (int i = 0; i < str.size(); i++)
            output[i] = str[i];
        return str.size();
    }
    int size = keypad(nums.substr(1), output);
    string* aux = new string[size];
    for (int i = 0; i < size; i++)
        aux[i] = output[i];
    int index = 0;
    int num = nums[0] - '0';
    string str = keys[num];
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < size; j++)
            output[index++] = str[i] + aux[j];
    }
    return index;
}

int main() {
    string str;
    getline(cin, str);

    int n = 1;
    for (int i = 0; i < str.size(); i++) {
        int num = str[i] - '0';
        n *= keys[num].size();
    }

    string *output = new string[n];
    int size = keypad(str, output);
    
    if (size != n)
        cout << "size mismatch" << endl;
    
    for (int i = 0; i < size; i++)
        cout << output[i] << endl;

    delete [] output;
    return 0;
}