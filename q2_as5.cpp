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
    cout << endl;
}

int countDelete(Node*& head, int key) {
    int count = 0;
    
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            count++;
        } else {
            temp = temp->next;
        }
    }
    
    return count;
}

int main() {
    Node* head = NULL;
    int n, x, key;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(head, x);
    }
    
    cin >> key;
    
    print(head);
    int count = countDelete(head, key);
    
    cout << "Count: " << count << endl;
    print(head);
    
    return 0;
}
