#include <iostream>
using namespace std;

int main() {

    int a[] = {1, 2, 3};
    char b[] = "abc";
    cout << a << endl;
    cout << b << endl;

    // char pointer behaves differently
    char * c = &b[0];
    cout << c << endl;

    char c1 = 'a';
    char * pc = &c1;
    cout << c1 << endl;
    cout << pc << endl; // prints till encounters a null char

    char str[] = "abcde"; // creates memory and init with the string and then copies it to the char array
    // readonly space usually
    char * pstr = "abcde"; // pointer points to the temp memory where the init string is stored, it's not explicitly copied for us

    cout << str << endl;
    cout << pstr << endl;

    cout << c << endl;
    c++;
    cout << c << endl;
    return 0;
}