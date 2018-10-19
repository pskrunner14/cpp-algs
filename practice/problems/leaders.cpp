#include <iostream>
using namespace std;

void leaders(int* arr, int len) {
  	
  	for (int i = 0; i < len; i++) {
      	bool leader = true;	
      	for (int j = i + 1; j < len; j++) {
          	if (arr[j] > arr[i]) {
              	leader = false;
          		break;
            }
        }
      	if (leader)
          	cout << arr[i] << " ";
    }
}

void Leaders(int* arr, int len) {
	/* Don't write main().
	 * Don't read input, it is passed as function argument.
	 * Print your output exactly in the same format as shown. 
	 * Don't print any extra line.
	*/
  	
  	int max = 0;
  	int* leaders = new int[len];
  	int index = 0;
  	for (int i = len - 1; i >= 0; i--) {
      	if (arr[i] >= max) {
          	leaders[index++] = arr[i];
          	max = arr[i];
        }
    }
  	for (int i = index - 1; i >= 0; i--)
      	cout << leaders[i] << " ";
}

int main() {

    int N;
    cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; i++) 
        cin >> arr[i];

    Leaders(arr, N);

    return 0;
}