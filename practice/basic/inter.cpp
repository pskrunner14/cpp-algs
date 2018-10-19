#include <iostream>
using namespace std;

void intersection(int input1[], int input2[], int size1, int size2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
	for (int i = 0; i < size1; i++) {
      	for (int j = 0; j < size2; j++) {
          	if (input1[i] == input2[j]) {
              	cout << input1[i] << endl;
            }
        }
    }
}

int main() {

    int n1, n2;
    
    cin >> n1;
    int a[n1];
    for (int i = 0; i < n1; i++)
        cin >> a[i];

    cin >> n2;
    int b[n2];
    for (int i = 0; i < n2; i++)
        cin >> b[i];

    intersection(a, b, n1, n2);

    return 0;
}
6
2 6 8 5 4 3
4
2 3 4 7 