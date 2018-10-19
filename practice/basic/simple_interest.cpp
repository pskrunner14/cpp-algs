/**
 * Calculate simple interest 
 * 
/*/ 

#include <iostream>
using namespace std;

int main() {
    
    int amount, time_periods;
    float interest_rate, simple_interest;

    cout << "Please enter [principal amount] [time periods] [interest rate]:" << endl;
    cin >> amount >> time_periods >> interest_rate;

    simple_interest = amount * (1 + interest_rate * time_periods);
    cout << "Simple interest: $" << simple_interest << endl;

    return 0;
}