#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
};

void addProduct(Node*& head, int id) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << "P" << temp->id << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void removeProduct(Node*& head, int id) {
    if (head == NULL) {
        cout << "Cart is empty" << endl;
        return;
    }

    if (head->id == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->id != id) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Product Not Found" << endl;
        return;
    }

    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

int main() {
    Node* head = NULL;

    addProduct(head, 101);
    addProduct(head, 205);
    addProduct(head, 310);
    addProduct(head, 415);

    cout << "Shopping Cart:" << endl;
    display(head);

    int id;
    cout << "Remove Product: P";
    cin >> id;

    removeProduct(head, id);

    cout << "Updated Cart:" << endl;
    display(head);

    return 0;
}