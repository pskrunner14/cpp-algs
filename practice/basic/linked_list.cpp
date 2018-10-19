#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {

    Node *root = new Node;
    root->data = 5;
    
    Node *node = new Node;
    node->data = 10;
    root->next = node;
    
    Node *temp = root;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}