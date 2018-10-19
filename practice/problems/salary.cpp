#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int basic, allow, totalSalary;
    float hra, da, pf;
    char grade;

    cin >> basic >> grade;

    hra = 0.2 * basic;
    da = 0.5 * basic;
    pf = 0.11 * basic;

    if (grade == 'A')
        allow = 1700;
    else if (grade == 'B')
        allow = 1500;
    else
        allow = 1300;

    totalSalary = round(basic + hra + da + allow - pf);
    cout << totalSalary << endl;

    return 0;
}