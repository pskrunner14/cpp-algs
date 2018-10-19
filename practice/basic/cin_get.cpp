#include <iostream>
using namespace std;

// cin ignores spaces and newlines
// cin.get does'nt ignore them
int main() {

    char c;
    int a = 'a', z = 'z', zero = '0', nine = '9', space = ' ', new_line = '\n', tab = '\t';
    int alphas = 0, nums = 0, specials = 0;
    c = cin.get();
    int count = 0;
    while (c != '$') {
        int ch = c;
        if (ch >= a && ch <= z)
            alphas++;
        else if (ch >= zero && ch <= nine) 
            nums++;
        else if (ch == new_line || ch == space || ch == tab)
            specials++;
        c = cin.get();
    }
    cout << alphas << " " << nums << " " << specials << endl;
    return 0;
}