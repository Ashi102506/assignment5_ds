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

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << "->NULL" << endl;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

int main() {
    Node* head = NULL;
    int n, x;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(head, x);
    }
    
    print(head);
    head = reverse(head);
    print(head);
    
    return 0;
}
