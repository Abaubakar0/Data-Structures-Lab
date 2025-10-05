#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void insertAtBegining(int value) {
        Node* n = new Node(value);
        n->next = head;
        head = n;
    }

    void insertAtEnd(int value) {
        Node* n = new Node(value);
        if (head == nullptr) {
            head = n;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = n;
    }

    void insertAtPosition(int value, int index) {
        Node* n = new Node(value);
        if (index == 0) {
            n->next = head;
            head = n;
            return;
        }
        Node* curr = head;
        for (int i = 1; i < index && curr != nullptr; i++) {
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Invalid position!" << endl;
            delete n;
            return;
        }
        n->next = curr->next;
        curr->next = n;
    }

    bool deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return false;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList l1;
    l1.insertAtBegining(1);
    l1.insertAtBegining(2);
    l1.insertAtBegining(3);

    cout << "Linked List: ";
    l1.display();

    l1.insertAtEnd(10);
    cout << "After inserting 10 at end: ";
    l1.display();

    l1.insertAtPosition(5, 2);
    cout << "After inserting 5 at index 2: ";
    l1.display();

    l1.deleteFromBeginning();
    cout << "After deleting from beginning: ";
    l1.display();

    return 0;
}
