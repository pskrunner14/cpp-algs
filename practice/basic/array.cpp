#include <iostream>
#include <climits>
using namespace std;

// here sizeof(arr) gives 8 as it needs 8 bytes to store an address in memory
// so explicitly define the size of the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

void arrange(int arr[],int n){
 
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Arrange elements in the array "arr" given as input.
     Taking input and printing output is handled automatically.
  */

    for (int i = 0; i < n; i++) {
      	arr[i] = i + 1;
    }
  	int arr_new[n];
	int li = 0;
  	int ri = n - 1;
  	for (int i = 0; i < n; i++) {
      	if (i % 2 == 0) {
          	arr_new[li] = arr[i];
      		li++;
    	} else {
          	arr_new[ri] = arr[i];
    		ri--;
        }
    }
	for (int i = 0; i < n; i++) {
      	arr[i] = arr_new[i];
    }
    print(arr, n);
}

int main() {

    // int min = INT_MIN;

    int n;
    cin >> n;

    int b[n];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    // int temp[3] = {1, 2, 3};
    arrange(b, n);

    // print_array(temp, 3);

    return 0;
}