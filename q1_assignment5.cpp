#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBegin(int x) {
    Node* n = new Node();
    n->data = x;
    n->next = head;
    head = n;
}

void insertEnd(int x) {
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

void insertBefore(int target, int x) {
    if (head == NULL) return;
    
    if (head->data == target) {
        insertBegin(x);
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == target) {
            Node* n = new Node();
            n->data = x;
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    }
}

void insertAfter(int target, int x) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            Node* n = new Node();
            n->data = x;
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    }
}

void deleteBegin() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteNode(int x) {
    if (head == NULL) return;
    
    if (head->data == x) {
        deleteBegin();
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == x) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            return;
        }
        temp = temp->next;
    }
}

int search(int x) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == x) {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int ch, x, target;
    
    while (true) {
        cout << "1.Insert Begin 2.Insert End 3.Insert Before 4.Insert After" << endl;
        cout << "5.Delete Begin 6.Delete End 7.Delete Node 8.Search 9.Display 0.Exit" << endl;
        cin >> ch;
        
        if (ch == 1) {
            cin >> x;
            insertBegin(x);
        }
        else if (ch == 2) {
            cin >> x;
            insertEnd(x);
        }
        else if (ch == 3) {
            cin >> target >> x;
            insertBefore(target, x);
        }
        else if (ch == 4) {
            cin >> target >> x;
            insertAfter(target, x);
        }
        else if (ch == 5) {
            deleteBegin();
        }
        else if (ch == 6) {
            deleteEnd();
        }
        else if (ch == 7) {
            cin >> x;
            deleteNode(x);
        }
        else if (ch == 8) {
            cin >> x;
            int pos = search(x);
            if (pos != -1) cout << "Position: " << pos << endl;
            else cout << "Not found" << endl;
        }
        else if (ch == 9) {
            display();
        }
        else if (ch == 0) {
            break;
        }
    }
    
    return 0;
}
