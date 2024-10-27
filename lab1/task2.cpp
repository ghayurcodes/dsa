#include<iostream>
using namespace std;

class Student{
    int age;
    int roll;
    float cgpa;
    string name;
    Student* nxtstdred;  // next student record
public:
    static int baseid;
    Student(string name, int age) {
        this->age = age;
        this->roll = baseid++;
        this->cgpa = 0;
        this->name = name;
        this->nxtstdred = NULL;
    }

    // Getters
    int getid() { return roll; }
    string getname() { return name; }
    float getgpa() { return cgpa; }
    int getage() { return age; }
    Student* getnext() { return nxtstdred; }

    // Setters
    void setgpa(float gpa) { this->cgpa = gpa; }
    void setnext(Student* s) { nxtstdred = s; }
};
int Student::baseid = 23100;

class StdList {
    Student *head;
    Student *current;
    int noR;  // no of records
   
public:
    StdList() {
        current = head = NULL;
        noR = 0;
    }

    void add() {
        string name;
        int age;
        float gpa;
        cout << "Enter name: ";
        getline(cin >> ws, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter CGPA: ";
        cin >> gpa;
    
        Student* newentry = new Student(name, age);
        newentry->setgpa(gpa);
        if (head == NULL) {
            head = newentry;
        } else {
            current = head;
            while (current->getnext() != NULL) {
                current = current->getnext();
            }
            current->setnext(newentry);
        }
        cout << "Student added\tRoll no: " << newentry->getid() << endl;
        noR++;
    }

    void del(int roll) {
        if (head == NULL) {
            cout << "Empty list\n";
            return;
        }

        if (head->getid() == roll) {  //special head case;
            Student* temp = head;
            head = head->getnext();
            delete temp;
            cout << "Record with id: " << roll << " deleted.\n";
            noR--;
            return;
        }

        current = head;
        while (current->getnext() != NULL) {
            if (current->getnext()->getid() == roll) {
                Student* todel = current->getnext();
                current->setnext(current->getnext()->getnext());
                delete todel;
                cout << "Record with id: " << roll << " deleted.\n";
                noR--;
                return;
            }
            current = current->getnext();
        }

        cout << "No such record found\n";
    }

    void update(int roll) {
        if (head == NULL) {
            cout << "Empty list\n";
            return;
        }

        current = head;
        while (current != NULL) {
            if (current->getid() == roll) {
                float gpa;
                do {
                    cout << "Enter new CGPA: ";
                    cin >> gpa;
                    if (gpa == current->getgpa()) {
                        cout << "Old CGPA entered. Please enter a new one.\n";
                        
                    }
                } while (gpa == current->getgpa());  

                current->setgpa(gpa);
                cout << "Record updated successfully\n";
                return;
            }
            current = current->getnext();
        }

        cout << "No such record found\n";
    }

    void search(int roll) {
        if (head == NULL) {
            cout << "Empty list\n";
            return;
        }

        int index = 0;
        current = head;
        while (current != NULL) {
            if (current->getid() == roll) {
                cout << "Record found at index: " << index << endl;
                return;
            }
            current = current->getnext();
            index++;
        }

        cout << "No such record exists\n";
    }

    void display() {
        if (head == NULL) {
            cout << "Empty list\n";
            return;
        }

        current = head;
        while (current != NULL) {
            cout << "Name: " << current->getname()<< " Age: " << current->getage()<< " Id: " << current->getid()<< " CGPA: " << current->getgpa() << endl;
            current = current->getnext();
        }
    }
};

int main() {
    int choice, id;
    StdList s;

    while (true) {
        cout << "\n\t=== Student Menu ===";
        cout << "\n\t1. Add Record";
        cout << "\n\t2. Delete Record";
        cout << "\n\t3. Update Record";
        cout << "\n\t4. Search Record";
        cout << "\n\t5. Display";
        cout << "\n\t6. Exit";
        cout << "\n\tEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.add();
                break;
            case 2:
                cout << "Enter Id:\n";
                cin >> id;
                s.del(id);
                break;
            case 3:
                cout << "Enter Id:\n";
                cin >> id;
                s.update(id);
                break;
            case 4:
                cout << "Enter Id:\n";
                cin >> id;
                s.search(id);
                break;
            case 5:
                s.display();
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid input\n";
        }
    }
}
