#include <iostream>
#include <cstring>
using namespace std;

int strLen(char str[]) {
    if (str[0] == '\0')
        return 0;
    return 1 + strLen(str + 1);
}

void removeX(char str[], char x) {
    if (str[0] == '\0')
        return;
    if (str[0] != x)
        removeX(str + 1, x);
    else {
        for (int i = 1; i <= strLen(str); i++)
            str[i - 1] = str[i];
        removeX(str, x);
    }
}

void removeDups(char str[]) {
    if (str[0] == '\0')
        return;
    if (str[0] != str[1])
        removeDups(str + 1);
    else {
        for (int i = 1; i <= strLen(str); i++)
            str[i - 1] = str[i];
        removeDups(str);
    }
}

int main() {
    char str[100], x;
    cin >> str;
    removeDups(str);
    cout << str << endl;
    return 0;
}