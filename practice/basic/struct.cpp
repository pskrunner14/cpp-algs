#include <iostream>
using namespace std;


struct Distance {
    int val;
};

Distance calculateAverage(Distance dist1, Distance dist2) {
    Distance avg;
    avg.val = (dist1.val + dist2.val) / 2; 
}

int main() {

    Distance dist1, dist2;
    cout << "Enter the distances: " << endl;
    cin >> dist1.val;
    cin >> dist2.val;

    Distance avg = calculateAverage(dist1, dist2);
    cout << "Average Distance is: " << avg.val << endl;

    return 0;
}