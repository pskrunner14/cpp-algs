/*
Given an integer array A of size N, check if the input array can be splitted in two parts such that -
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.
Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.
Return true, if array can be split according to the above rules, else return false.
*/

bool check_valid(int* arr1, int size1, int* arr2, int size2) {
  	bool one_five = false;
  	bool one_three = false;
  	for (int i = 0; i < size1; i++) {
      	if (arr1[i] % 3 == 0) {
          	one_three = true;
        }
      	if (arr1[i] % 5 == 0) {
          	one_five = true;
        }
      	if (one_five == true && one_three == true) {
      		return false;
    	}
    }
  	if (one_five == true && one_three == true) {
      	return false;
    }
  	bool two_five = false;
  	bool two_three = false;
	for (int i = 0; i < size2; i++) {
      	if (arr2[i] % 3 == 0) {
          	two_three = true;
        }
      	if (arr2[i] % 5 == 0) {
          	two_five = true;
        }
      	if (two_five == true && two_three == true) {
      		return false;
    	}
    }
  	if (two_five == true && two_three == true) {
      	return false;
    }
  	if ((one_three == true && two_three == true) || (one_five == true && two_five == true)) {
      	return false;
    }
  	return true;
}

bool split_helper(int* input1, int sum1, int size1, int* input2, int sum2, int size2) {
  	if (size1 == 0) {
      	return false;
    }
  	if (sum1 == sum2) {
      	if (check_valid(input1, size1, input2, size2)) {
          	return true;
        }
      	return false;
    }
  	for (int i = 0; i < size1; i++) {
      	int num = input1[i];
      	int *input1_aux = input1;
      	for (int j = i; j < size1 - 1; j++) {
          	input1_aux[j] = input1_aux[j + 1];
        }
      	int *input2_aux = input2;
      	input2_aux[size2] = num;
      	bool status = split_helper(input1_aux, sum1 - num, size1 - 1, input2_aux, sum2 + num, size2 + 1);
      	if (status) {
          	return true;
        }
    }
  	return false;
}


bool splitArray(int *input, int size) {
  	int *input2 = new int[50];
  	int sum = 0;
  	for (int i = 0; i < size; i++) {
      	sum += input[i];
    }
	bool status = split_helper(input, sum, size, input2, 0, 0);
	delete [] input2;
  	return status;
}

#include <iostream>
using namespace std;

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	return 0;
}