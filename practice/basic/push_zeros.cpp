#include <iostream>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

void pushZeroesEnd(int arr[], int n){
  	int li = 0, ri = n - 1;
  	while (arr[ri] == 0) {
        ri--;
    }
  	while (li < ri) {
      	int key = arr[li];
      	if (key == 0) {
          	for (int i = li; i < ri; i++) {
              	arr[i] = arr[i + 1];
            }
          	arr[ri] = key;
          	ri--;
        }
      	li++;
    }
    print_array(arr, n);
}

int main() {

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    pushZeroesEnd(arr, n);

    return 0;
}