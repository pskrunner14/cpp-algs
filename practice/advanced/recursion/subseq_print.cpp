#include <iostream>
#include <cstring>
using namespace std;

// better space complexity than returning the subsequences
// we're passing the decision down to the leaf nodes to handle
// binary tree with 2^n leaf nodes
void print_subseq(string input, string output) {
    if (input.empty()) {
        cout << output << endl;
        return;
    }
    print_subseq(input.substr(1), output); // remove first char and feed output as is
    print_subseq(input.substr(1), output + input[0]); // remove first char in input and put in output
}

int main() {

    string str;
    string output = "";
    getline(cin, str);

    print_subseq(str, output);
    return 0;
}