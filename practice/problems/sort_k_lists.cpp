#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool not_empty(vector<ListNode*>& lists) {
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != NULL)
            return true;
    }
    return false;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> main;
    while (not_empty(lists)) {
        vector<int> list;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                list.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        sort(list.begin(), list.end());
        for (int i = 0; i < list.size(); i++)
            main.push_back(list[i]);   
    }
    sort(main.begin(), main.end());
    ListNode *head = NULL;
    ListNode *temp = head;
    for (int i = 0; i < main.size(); i++) {
        ListNode *new_node = new ListNode(main[i]);
        if (head == NULL) {
            head = new_node;
            temp = head;
        } else {
            temp->next = new_node;
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    vector<ListNode*> lists;

    vector<vector<int>>vect = {{1, 4, 5}, 
                               {1, 3, 4}, 
                               {2, 6}}; 

    for (int i = 0; i < vect.size(); i++) {
        ListNode* head = NULL;
        ListNode* temp = NULL;
        for (int j = 0; j < vect[i].size(); j++) {
            ListNode* new_node = new ListNode(vect[i][j]);
            if (head == NULL) {
                temp = new_node;
                head = temp;
            } else {
                temp->next = new_node;
                temp = temp->next;
            }
        }
        lists.push_back(head);
    }
    ListNode* sorted = mergeKLists(lists);
    for (ListNode* temp = sorted; temp != NULL; temp = temp->next)
        cout << temp->val << " ";
    cout << endl;
    return 0;
}