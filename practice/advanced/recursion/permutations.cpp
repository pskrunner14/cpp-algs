#include <cstring>
#include <iostream>
using namespace std;

int returnPermutations(string input, string output[]) {
    if (input.empty()) {
        output[0] = "";
        return 1;
    }
    int size = 0;
    for (int i = 0; i < input.size(); i++) {
        string copy = input;
        copy.erase(i, 1);
        string *out_copy = new string[10000];
        int size_copy = returnPermutations(copy, out_copy);
        for (int j = 0; j < size_copy; j++) {
            output[size + j] = input.at(i) + out_copy[j];
        }
        delete[] out_copy;
        size += size_copy;
    }
    return size;
}

int main() {
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++) {
        cout << output[i] << endl;
    }
    return 0;
}