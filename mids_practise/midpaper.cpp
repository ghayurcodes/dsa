#include<iostream>
#include<string>
using namespace std;

class Book {
    string title;
    string author;
    int isbn;
    bool status;
    Book* next;

public:
    Book() : next(nullptr) {}

    Book(string t, string a, int isbn, bool b)
        : title(t), author(a), isbn(isbn), status(b), next(nullptr) {}

    string get_title() { return title; }
    string get_author() { return author; }
    int get_isbn() { return isbn; }
    bool get_status() { return status; }
    Book* get_next() { return next; }
    void set_next(Book* b) { next = b; }
};

class Catalog {
    Book* head;

public:
    Catalog() : head(nullptr) {}

    void add() {
        string t, a;
        int i;
        bool s;
        cout << "Enter title:\n";
        cin >> ws; 
        getline(cin, t);
        cout << "Enter author:\n";
        getline(cin, a);
        cout << "Enter ISBN:\n";
        cin >> i;
        cout << "Enter status (1 for available, 0 for not available):\n";
        cin >> s;

        Book* newbook = new Book(t, a, i, s);

        if (head == nullptr) {
            head = newbook;
        } else {
            Book* temp = head;
            while (temp->get_next() != nullptr) {
                temp = temp->get_next();
            }
            temp->set_next(newbook);
        }
    }

    void del(int isbn) {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }

        if (head->get_isbn() == isbn) {
            Book* todel = head;
            head = head->get_next();
            delete todel;
            cout << "Book with ISBN " << isbn << " deleted\n";
            return;
        }

        Book* temp = head;
        while (temp->get_next() != nullptr && temp->get_next()->get_isbn() != isbn) {
            temp = temp->get_next();
        }

        if (temp->get_next() == nullptr) {
            cout << "Book with ISBN " << isbn << " not found\n";
        } else {
            Book* todel = temp->get_next();
            temp->set_next(todel->get_next());
            delete todel;
            cout << "Book with ISBN " << isbn << " deleted\n";
        }
    }

    void print() {
        Book* temp = head;
        while (temp != nullptr) {
            cout << "Book title: " << temp->get_title()
                 << "\tStatus: " << (temp->get_status() ? "available" : "not available") << "\n";
            temp = temp->get_next();
        }
    }

    void search_author(string author) {
        Book* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->get_author() == author) {
                cout << "---------BOOK FOUND--------\n";
                cout << "Book: " << temp->get_title() << "\tAuthor: " << temp->get_author() << endl;
                found = true;
                break;
            }
            temp = temp->get_next();
        }
        if (!found) {
            cout << "No book found\n";
        }
    }

    void available() {
        Book* temp = head;
        cout << "---------AVAILABLE BOOKS--------\n";
        while (temp != nullptr) {
            if (temp->get_status()) {
                cout << "Book: " << temp->get_title()
                     << "\tAuthor: " << temp->get_author()
                     << "\tISBN: " << temp->get_isbn()
                     << "\tSTATUS: Available\n";
            }
            temp = temp->get_next();
        }
    }
};

int main() {
    Catalog c;
    int opt, choice;
    string author;
    while (true) {
        cout << "---------WELCOME--------\n";
        cout << "Press 1: Create a book and add it\n";
        cout << "Press 2: Delete a book from the catalog using ISBN\n";
        cout << "Press 3: Print all books present in catalog\n";
        cout << "Press 4: Search a book by its author name\n";
        cout << "Press 5: Print all the books that are available\n";
        cout << "Press 6: EXIT\n";

        cin >> opt;

        switch (opt) {
            case 1:
                c.add();
                break;

            case 2:
                cout << "Enter ISBN:\n";
                cin >> choice;
                c.del(choice);
                break;

            case 3:
                c.print();
                break;

            case 4:
                cout << "Enter author name:\n";
                cin >> ws;
                getline(cin, author);
                c.search_author(author);
                break;

            case 5:
                c.available();
                break;

            case 6:
                cout << "Exiting.....\n";
                return 0;

            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }
}
