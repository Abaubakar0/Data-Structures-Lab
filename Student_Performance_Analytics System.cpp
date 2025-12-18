#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/* ===================== DATA STRUCTURES ===================== */

struct Student {
    int id;
    string name;
    string dept;
    int semester;
    float cgpa;
    int credits;
    int year;
};

struct Node {
    Student data;
    Node* next;
};

/* ===================== LINKED LIST UTILITIES ===================== */

Node* createNode(const Student& s) {
    Node* n = new Node;
    n->data = s;
    n->next = nullptr;
    return n;
}

void appendNode(Node*& head, const Student& s) {
    Node* n = createNode(s);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}

Node* copyList(Node* head) {
    Node* newHead = nullptr;
    while (head) {
        appendNode(newHead, head->data);
        head = head->next;
    }
    return newHead;
}

void freeList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

/* ===================== FILE INPUT ===================== */

Node* readStudents(const string& filename, int& total) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error opening input file.\n";
        return nullptr;
    }

    fin >> total;
    fin.ignore();

    Node* head = nullptr;
    for (int i = 0; i < total; i++) {
        Student s;
        fin >> s.id;
        fin.ignore();
        getline(fin, s.name, ' ');
        getline(fin, s.name, ' ');
        fin >> s.dept >> s.semester >> s.cgpa >> s.credits >> s.year;

        if (s.cgpa < 0 || s.cgpa > 4 || s.semester < 1 || s.semester > 8)
            continue; // basic validation

        appendNode(head, s);
    }
    fin.close();
    return head;
}

/* ===================== SORT 1: BUBBLE (CGPA) ===================== */

void bubbleSortCGPA(Node* head) {
    bool swapped;
    do {
        swapped = false;
        Node* p = head;
        while (p && p->next) {
            Student& a = p->data;
            Student& b = p->next->data;

            if (a.cgpa < b.cgpa ||
               (a.cgpa == b.cgpa && a.credits < b.credits)) {
                swap(a, b);
                swapped = true;
            }
            p = p->next;
        }
    } while (swapped);
}

/* ===================== SORT 2: INSERTION (YEAR + ID) ===================== */

Node* insertionSortYear(Node* head) {
    Node* sorted = nullptr;

    while (head) {
        Node* curr = head;
        head = head->next;

        if (!sorted || 
            curr->data.year < sorted->data.year ||
           (curr->data.year == sorted->data.year &&
            curr->data.id < sorted->data.id)) {

            curr->next = sorted;
            sorted = curr;
        } else {
            Node* temp = sorted;
            while (temp->next &&
                  (temp->next->data.year < curr->data.year ||
                  (temp->next->data.year == curr->data.year &&
                   temp->next->data.id < curr->data.id))) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
    }
    return sorted;
}

/* ===================== OUTPUT FILE 1 ===================== */

void writeRankedByCGPA(Node* head) {
    ofstream fout("ranked_by_cgpa.txt");

    fout << "====================================================\n";
    fout << "        STUDENTS RANKED BY CGPA\n";
    fout << "====================================================\n";
    fout << "Rank | ID     | Name              | Dept | Sem | CGPA | Credits | Year\n";
    fout << "----------------------------------------------------\n";

    int rank = 1;
    while (head) {
        fout << setw(4) << rank++ << " | "
             << setw(6) << head->data.id << " | "
             << setw(17) << left << head->data.name << right << " | "
             << setw(4) << head->data.dept << " | "
             << setw(3) << head->data.semester << " | "
             << fixed << setprecision(2) << setw(4) << head->data.cgpa << " | "
             << setw(7) << head->data.credits << " | "
             << head->data.year << "\n";
        head = head->next;
    }
    fout.close();
}

/* ===================== OUTPUT FILE 2 ===================== */

void writeSortedByEnrollment(Node* head) {
    ofstream fout("sorted_by_enrollment.txt");

    int currentYear = -1;
    float sum = 0;
    int count = 0;

    while (head) {
        if (head->data.year != currentYear) {
            if (count > 0) {
                fout << "Average CGPA: " << fixed << setprecision(2)
                     << sum / count << "\n\n";
            }
            currentYear = head->data.year;
            sum = 0;
            count = 0;
            fout << "==== Enrollment Year: " << currentYear << " ====\n";
        }
        fout << head->data.id << " "
             << head->data.name << " "
             << head->data.cgpa << "\n";

        sum += head->data.cgpa;
        count++;
        head = head->next;
    }

    if (count > 0)
        fout << "Average CGPA: " << sum / count << "\n";

    fout.close();
}

/* ===================== MAIN ===================== */

int main() {
    int total = 0;
    Node* original = readStudents("students_data.txt", total);
    if (!original) return 1;

    // Output 1
    Node* cgpaList = copyList(original);
    bubbleSortCGPA(cgpaList);
    writeRankedByCGPA(cgpaList);
    freeList(cgpaList);

    // Output 2
    Node* yearList = copyList(original);
    yearList = insertionSortYear(yearList);
    writeSortedByEnrollment(yearList);
    freeList(yearList);

    freeList(original);
    return 0;
}