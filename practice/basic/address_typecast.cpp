#include <iostream>
using namespace std;

int main() {

    int i = 65;

    int *p = &i;
    char *pc = (char*) p; // explicit typecasting

    cout << *p << endl; // prints 65
    cout << *pc << endl; // prints A (because the int bytes are stored in reverse order)
    // most significant bits are on the left
    // in little endian system*

    cout << *(pc + 1) << endl;
    cout << *(pc + 2) << endl;
    cout << *(pc + 3) << endl;

    cout << p << endl;
    cout << pc << endl;

    return 0;
}