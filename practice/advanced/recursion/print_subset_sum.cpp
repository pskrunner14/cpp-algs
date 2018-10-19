#include <iostream>
using namespace std;

void helper(int input[], int size, int k, int output[]) {
    if (size == 0) {
      	if (k == 0) {
        	for (int i = 1; i < output[0] + 1; i++) {
            	cout << output[i] << " ";
            }
          	cout << endl;
        }
      	return;
    }
  	helper(input + 1, size - 1, k, output);
  	int aux[1000];
  	aux[0] = output[0] + 1;
  	for (int i = 1; i < output[0] + 1; i++) {
      	aux[i] = output[i];
    }
  	aux[aux[0]] = input[0];
  	helper(input + 1, size - 1, k - input[0], aux);
}

void printSubsetSumToK(int input[], int size, int k) {
  	int output[1000];
  	output[0] = 0;
  	helper(input, size, k, output);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}