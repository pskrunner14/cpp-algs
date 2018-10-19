#include <iostream>
using namespace std;

// input - given string
// You need to update in the given string itself. No need to print or return anything

void reverseStringWordWise(char input[]) {
  	int num_words = 1;
	int i = 0;
  	while (input[i] != '\0') {
      	if (input[i] == ' ') {
          	num_words++;
        }
      	i++;
    }
  	cout << num_words << endl;
  	char words[num_words][100];
  	int global_index = 0;
  	for (int i = 0; i < num_words; i++) {
      	int local_index = 0;
      	while (input[global_index] != ' ' && input[global_index] != '\0') {
      		words[i][local_index] = input[global_index];
            local_index++;
          	global_index++;
    	}
      	global_index++;
      	words[i][local_index] = '\0';
    	for (int j = 0; words[i][j] != '\0'; j++)
          	cout << words[i][j];
      	cout << endl;
    }
}

int main() {

    char name[200];
    cin.getline(name, 200);
    reverseStringWordWise(name);
    return 0;
}