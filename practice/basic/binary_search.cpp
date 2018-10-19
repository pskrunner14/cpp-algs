#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int val){	
	
  	int start = 0;
  	int end = n - 1;
	int mid;
  	while (start < end) {
      	mid = (start + end) / 2;
      	if (arr[mid] == val)
          	return mid;
        else if (arr[mid] > val)
          	end = mid - 1;
        else
          	start = mid + 1;
    }
  	return -1;
}

int main() {

    return 0;
}