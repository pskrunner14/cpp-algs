#include <iostream>
using namespace std;

void print_array(int arr[][100], int m, int n) { // have to specify the column size
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          	cout << arr[i][j] << " ";
        }
      	cout << endl;
    }
}

int main() {
    
    int m, n;
  	cin >> m >> n;
  
  	int arr[m][100];  // have to define the column size
  
  	for (int i = 0; i < m; i++) {
      	for (int j = 0; j < n; j++) {
          	cin >> arr[i][j];
        }
    }

    print_array(arr, m, n);

    int test[][100] = {{1, 2}, {15, 16}};
    print_array(test, 2, 2);

    return 0;
}

/*
#include <cstring>
// input - given string
// You need to update in the given string itself i.e. in input. No need to return or print.

void stringCompression(char input[]) {
    // Write your code here
	char curr_ch = input[0];
  	int curr_len = 1;
  	int i = 1;
  	while (input[i] != '\0') {
      	if (input[i] == curr_ch) {
          	curr_len += 1;
        } else {
			if (curr_len > 1) {
             	int index = i - 1;
              	while (index > i - curr_len + 1)
              		input[index--] = '%';
          		input[index] = '0' + curr_len;
            }
          	curr_ch = input[i];
          	curr_len = 1;
        }
      	i++;
    }
  	int index = 0;
  	for (int i = 0; i < strlen(input); i++) {
      	if (input[i] != '%')
          	input[index++] = input[i];
    }
  	input[index] = '\0';
}
*/