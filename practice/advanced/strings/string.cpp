#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // string is just a class
    // and stores data in char 
    // array on the backend

    string ss;
    getline(cin, ss);
    cout << ss << endl;
    cout << ss.size() << endl;
    cout << ss.length() << endl;
    cout << ss.substr(1) << endl;
    cout << ss.substr(3) << endl; // all chars after 3rd char
    cout << ss.substr(3, 5) << endl; // 5 chars after 3rd chars

    cout << ss.find("hel") << endl; // returns first index of the string if found

    string s = "abc";
    string s1;
    s1 = "def";
    cout << s << endl;
    cout << s1 << endl;

    string s3 = s + s1; // or s += s1
    cout << s3 << endl;

    // create a new string dynamically
    string *sp = new string;
    *sp = "ghi";
    cout << *sp << endl;

    string *s2 = new string;
    cin >> *s2; // takes input only till 
    cout << *s2 << endl;
    return 0;
}