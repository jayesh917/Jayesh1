#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct Client {
    string name;
    long long phone;
    bool isEmpty;

    Client() {
        name = "";
        phone = 0;
        isEmpty = true;
    }
};

class HashTable {
    Client table[TABLE_SIZE];

    int hash1(long long key) {
        return key % TABLE_SIZE;
    }

    int hash2(long long key) {
        int prime = 7;
        return prime - (key % prime);
    }

public:
    void insertLinear(string name, long long phone) {
        int index = hash1(phone);
        int i = 0;
        while (!table[(index + i) % TABLE_SIZE].isEmpty && i < TABLE_SIZE) {
            i++;
        }
        if (i < TABLE_SIZE) {
            int pos = (index + i) % TABLE_SIZE;
            table[pos].name = name;
            table[pos].phone = phone;
            table[pos].isEmpty = false;
        } else {
            cout << "Hash Table is Full (Linear Probing)!" << endl;
        }
    }

    void insertQuadratic(string name, long long phone) {
        int index = hash1(phone);
        int i = 0;
        while (!table[(index + i * i) % TABLE_SIZE].isEmpty && i < TABLE_SIZE) {
            i++;
        }
        if (i < TABLE_SIZE) {
            int pos = (index + i * i) % TABLE_SIZE;
            table[pos].name = name;
            table[pos].phone = phone;
            table[pos].isEmpty = false;
        } else {
            cout << "Hash Table is Full (Quadratic Probing)!" << endl;
        }
    }

    void insertDoubleHashing(string name, long long phone) {
        int index = hash1(phone);
        int step = hash2(phone);
        int i = 0;
        while (!table[(index + i * step) % TABLE_SIZE].isEmpty && i < TABLE_SIZE) {
            i++;
        }
        if (i < TABLE_SIZE) {
            int pos = (index + i * step) % TABLE_SIZE;
            table[pos].name = name;
            table[pos].phone = phone;
            table[pos].isEmpty = false;
        } else {
            cout << "Hash Table is Full (Double Hashing)!" << endl;
        }
    }

    void search(long long phone) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!table[i].isEmpty && table[i].phone == phone) {
                cout << "Found: " << table[i].name << " -> " << table[i].phone << endl;
                return;
            }
        }
        cout << "Phone number not found!" << endl;
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!table[i].isEmpty) {
                cout << i << " --> " << table[i].name << " : " << table[i].phone << endl;
            } else {
                cout << i << " --> [Empty]\n";
            }
        }
    }
};

int main() {
    HashTable ht;
    int choice;
    string name;
    long long phone;

    do {
        cout << "\n---- Telephone Book (Hashing) ----\n";
        cout << "1. Insert (Linear Probing)\n";
        cout << "2. Insert (Quadratic Probing)\n";
        cout << "3. Insert (Double Hashing)\n";
        cout << "4. Search\n";
        cout << "5. Display Table\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Phone Number: ";
                cin >> phone;
                ht.insertLinear(name, phone);
                break;
            case 2:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Phone Number: ";
                cin >> phone;
                ht.insertQuadratic(name, phone);
                break;
            case 3:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Phone Number: ";
                cin >> phone;
                ht.insertDoubleHashing(name, phone);
                break;
            case 4:
                cout << "Enter Phone Number to Search: ";
                cin >> phone;
                ht.search(phone);
                break;
            case 5:
                ht.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 6);

    return 0;
}
