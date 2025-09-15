#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int x) {
    Node* n = new Node();
    n->data = x;
    n->next = NULL;
    
    if (head == NULL) {
        head = n;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow->data;
}

int main() {
    Node* head = NULL;
    int n, x;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(head, x);
    }
    
    int middle = findMiddle(head);
    cout << middle << endl;
    
    return 0;
}
