#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    vector<vector<char>> rows;
    for (int i = 0; i < numRows; i++) {
        vector<char> row;
        rows.push_back(row);
    }
    int index = 0;
    while (index < s.size()) {
        for (int i = 0; i < numRows; i++) {
            if (index >= s.size())
                break;
            rows[i].push_back(s[index++]);
        }
        for (int i = numRows - 1; i > 0; i--) {
            if (index >= s.size())
                break;
            rows[i].push_back(s[index++]);
        }
    }
    string newString = "";
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rows[i].size(); j++)
            newString.push_back(rows[i][j]);
    }
    return newString;
}

int main() {

    cout << convert("PAYPALISHIRING", 3) << endl;

    return 0;
}