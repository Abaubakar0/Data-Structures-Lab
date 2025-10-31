#include <iostream>
using namespace std;

struct patient {
    int patient_id;
    patient *next;
    patient *prev;

    patient(int pid) {
        patient_id = pid;
        next = nullptr;
        prev = nullptr;
    }
};

class erlist {


public:
	  patient *head;
      patient *tail;
      
    erlist() {
        head = nullptr;
        tail = nullptr;
    }

    ~erlist() {
        patient *curr = head;
        while (curr != nullptr) {
            patient *temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        cout << "All patients have been deleted (Queue cleared)." << endl;
    }

    void insertAtBeginning(int pid) {
        patient *n = new patient(pid);
        if (head == nullptr) {      
            head = tail = n;
            return;
        }
        n->next = head;               
        head->prev = n;             
        head = n;                     
    }

    void insertAtEnd(int pid) {
        patient *n = new patient(pid);
        if (tail == nullptr) {        
            head = tail = n;
            return;
        }
        tail->next = n;               
        n->prev = tail;               
        tail = n;                     
    }

    
    void insertAtPosition(int pid, int i) {
        if (i <= 1 || head == nullptr) {  
            insertAtBeginning(pid);
            return;
        }

        patient *cur = head;
        int index = 1;

        
        while (cur != nullptr && index < i) {
            cur = cur->next;
            index++;
        }

        if (cur == nullptr) {  
            insertAtEnd(pid);
            return;
        }


        patient *n = new patient(pid);
        patient *prevNode = cur->prev;

        n->next = cur;
        n->prev = prevNode;

        prevNode->next = n;
        cur->prev = n;
    }

    
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "No patients to delete.\n";
            return;
        }

        patient *Delete = head;

        if (head == tail) {           
            head = tail = nullptr;
        } else {
            head = head->next;        
            head->prev = nullptr;
        }

        cout << "Patient " << Delete->patient_id << " removed from beginning.\n";
        delete Delete;
    }

    
    void display() {
        if (head == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        patient *temp = head;
        cout << "Patients in ER queue: ";
        while (temp != nullptr) {
            cout << temp->patient_id << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    erlist e;
    cout << "\n================= ER PATIENT MANAGEMENT =================\n";

    e.insertAtEnd(101);
    e.insertAtEnd(102);
    e.insertAtBeginning(200);
    e.insertAtPosition(150, 2);
    e.deleteFromBeginning();
    e.insertAtEnd(300);
    e.display();

    return 0;
}
