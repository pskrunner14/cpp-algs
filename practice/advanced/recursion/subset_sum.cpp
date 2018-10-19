#include <iostream>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k) {
	if (n == 0) {
      	if (k == 0) {
          	output[0][0] = 0;
          	return 1;
        }
      	return 0;
    }
  	// with input[0]
  	int arr1[1000][50];
  	int size1 = subsetSumToK(input + 1, n - 1, arr1, k - input[0]);
  	// without input[0]
  	int arr2[1000][50];
  	int size2 = subsetSumToK(input + 1, n - 1, arr2, k);
  	// merge the two solutions
	for (int i = 0; i < size1; i++) {
      	output[i][0] = arr1[i][0] + 1;
      	output[i][1] = input[0];
      	for (int j = 2; j < arr1[i][0] + 2; j++) {
          	output[i][j] = arr1[i][j - 1];
        }
    }
  	for (int i = 0; i < size2; i++) {
      	for (int j = 0; j < arr2[i][0] + 1; j++) {
          	output[size1 + i][j] = arr2[i][j];
        }
    }
  	return size1 + size2;
}

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}