#include <iostream>
#include <string>

using namespace std;


struct InventoryItem {
    int id;
    string name;
    InventoryItem* next;
    InventoryItem* prev;

    InventoryItem(int i, string n) : id(i), name(n), next(nullptr), prev(nullptr) {}
};


class InventoryList {
private:
    InventoryItem* head;
    InventoryItem* tail;

public:
    InventoryList() : head(nullptr), tail(nullptr) {}

   
    void addItem(int id, string name) {
        InventoryItem* newItem = new InventoryItem(id, name);
        if (!head) {
            head = tail = newItem;
        } else {
            newItem->next = head;
            head->prev = newItem;
            head = newItem;
        }
        cout << "Item added: ID = " << id << ", Name = " << name << endl;
    }

   
    void removeItem() {
        if (!tail) {
            cout << "Inventory is empty.\n";
            return;
        }
        cout << "Item removed: ID = " << tail->id << ", Name = " << tail->name << endl;

        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }

  
    void updateItem(int id, string newName) {
        if (!head) {
            cout << "Inventory is empty.\n";
            return;
        }

        InventoryItem* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "Item updated: ID = " << id << ", Old Name = " << temp->name << ", New Name = " << newName << endl;
                temp->name = newName;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found.\n";
    }

    void displayItems() {
        if (!head) {
            cout << "No inventory items.\n";
            return;
        }
        InventoryItem* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    InventoryList inventory;

    inventory.addItem(101, "laptop");
    inventory.addItem(102, "iphone");
    inventory.addItem(103, "watch");

    cout << "\nDisplaying inventory items:\n";
    inventory.displayItems();

    cout << "\nUpdating item with ID 102:\n";
    inventory.updateItem(102, "Iphone Pro");

    cout << "\nDisplaying inventory after update:\n";
    inventory.displayItems();

    cout << "\nRemoving the last item:\n";
    inventory.removeItem();

    cout << "\nDisplaying inventory after removal:\n";
    inventory.displayItems();

    return 0;
}
