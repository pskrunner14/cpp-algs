#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char str[100];
    cin >> str;

    // length of strings
    int len = strlen(str);
    cout << len << endl;

    char str1[100];
    char str2[100];

    cin >> str1;
    cin >> str2;

    // compare two strings
    if (!strcmp(str1, str2))
        cout << "Same!" << endl;
    else
        cout << "Nope!" << endl;

    char a[100] = "def";
    char b[100] = "abcd";
    char c[100];

    // copy a string into another
    strcpy(a, b);   // copies null char also
    cout << a << endl;

    strcpy(c, "hello");
    cout << c << endl;

    // copy first n chars from one string to another
    char d[100] = "     ,world!";   // does'nt copy null char on its own
    char e[100] = "hello world!";   // appends null chars if source string is finished

    strncpy(d, e, 5);
    cout << d << endl;

    return 0;
}