#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* next;
};

void addStudent(Node*& head, int roll) {
    Node* newNode = new Node;
    newNode->roll = roll;
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
        cout << temp->roll << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void searchStudent(Node* head, int roll) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            cout << "Student Found" << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student Not Found" << endl;
}

int main() {
    Node* head = NULL;

    addStudent(head, 101);
    addStudent(head, 105);
    addStudent(head, 108);
    addStudent(head, 112);

    cout << "Registered Students:" << endl;
    display(head);

    int roll;
    cout << "Enter Roll Number to Search: ";
    cin >> roll;

    searchStudent(head, roll);

    return 0;
}
