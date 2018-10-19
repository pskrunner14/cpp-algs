#include <iostream>
using namespace std;

int main(){

    /* Read input as specified in the question.
	 * Print output as specified in the question.
	 */
  	int m, n;
  	cin >> m >> n;
  
  	int arr[m][n];
  
  	for (int i = 0; i < m; i++) {
      	for (int j = 0; j < n; j++) {
          	cin >> arr[i][j];
        }
    }
  
  	for (int j = 0; j < n; j++) {
      	int col_sum = 0;
      	for (int i = 0; i < m; i++) {
          	col_sum += arr[i][j];
        }
      	cout << col_sum << " ";
    }
  
  	return 0;
}