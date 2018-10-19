#include <iostream>
using namespace std;

void printTable(int start, int end, int step) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    for (int f = start; f <= end; f += step) {
        int c = (5.0 / 9) * (f - 32);
        cout << f << "\t" << c << endl;
    }
    
} 

int main() {

    return 0;
}