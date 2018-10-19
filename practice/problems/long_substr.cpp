#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

void print_substr(char str[], int start, int end) {
    for (int i = start; i < end; i++)
        cout << str[i];
    cout << endl;
}

int main() {
    char arr[200];
    cin >> arr;
    unordered_map<char, bool> map;
    int li = 0, max_li = 0;
    int max_len = 0;
    for (int i = 0; i < strlen(arr); i++) {
        if (map.count(arr[i]) > 0) {
            if ((i - li) > max_len) {
                max_len = i - li;
                max_li = li;
            }
            while (map.count(arr[i]) > 0)
                map.erase(arr[li++]);
        }
        map[arr[i]] = true;
    }
    print_substr(arr, max_li, max_li + max_len);
    return 0;
}