#include <iostream>
#include <string>
using namespace std;

struct Node {
    string prn;
    string name;
    Node* next;
    Node(string p, string n) {
        prn = p;
        name = n;
        next = nullptr;
    }
};

class Club {
    Node* head;

public:
    Club() {
        head = nullptr;
    }

    void addPresident(string prn, string name) {
        Node* newNode = new Node(prn, name);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        cout << "President added!\n";
    }

    void addSecretary(string prn, string name) {
        Node* newNode = new Node(prn, name);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Secretary added!\n";
    }

    void addMember(string prn, string name) {
        if (head == nullptr) {
            cout << "Please add President first!\n";
            return;
        }
        Node* newNode = new Node(prn, name);
        Node* temp = head;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Member added!\n";
    }

    void deletePresident() {
        if (head == nullptr) {
            cout << "No members to delete!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "President deleted!\n";
    }

    void deleteSecretary() {
        if (head == nullptr) {
            cout << "No members to delete!\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Secretary deleted!\n";
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
        cout << "Secretary deleted!\n";
    }

    void deleteMember(string prn) {
        if (head == nullptr) {
            cout << "No members in the club!\n";
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->prn != prn) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Member not found!\n";
            return;
        }
        if (prev == nullptr) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Member deleted!\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "No members in the club!\n";
            return;
        }
        Node* temp = head;
        cout << "\nClub Members:\n";
        while (temp != nullptr) {
            cout << "PRN: " << temp->prn << " | Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    int countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void concatenate(Club& other) {
        if (head == nullptr) {
            head = other.head;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = other.head;
    }
};

int main() {
    Club divisionA, divisionB;
    int choice;
    string prn, name;

    do {
        cout << "\n===== Pinnacle Club Menu =====\n";
        cout << "1. Add President (Division A)\n";
        cout << "2. Add Secretary (Division A)\n";
        cout << "3. Add Member (Division A)\n";
        cout << "4. Delete President (Division A)\n";
        cout << "5. Delete Secretary (Division A)\n";
        cout << "6. Delete Member (by PRN) (Division A)\n";
        cout << "7. Display Members (Division A)\n";
        cout << "8. Count Members (Division A)\n";
        cout << "9. Add President (Division B)\n";
        cout << "10. Add Secretary (Division B)\n";
        cout << "11. Concatenate Division B into Division A\n";
        cout << "12. Display Members (Division A after concatenation)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter PRN and Name: ";
                cin >> prn >> name;
                divisionA.addPresident(prn, name);
                break;
            case 2:
                cout << "Enter PRN and Name: ";
                cin >> prn >> name;
                divisionA.addSecretary(prn, name);
                break;
            case 3:
                cout << "Enter PRN and Name: ";
                cin >> prn >> name;
                divisionA.addMember(prn, name);
                break;
            case 4:
                divisionA.deletePresident();
                break;
            case 5:
                divisionA.deleteSecretary();
                break;
            case 6:
                cout << "Enter PRN to delete: ";
                cin >> prn;
                divisionA.deleteMember(prn);
                break;
            case 7:
                divisionA.display();
                break;
            case 8:
                cout << "Total Members: " << divisionA.countMembers() << endl;
                break;
            case 9:
                cout << "Enter PRN and Name: ";
                cin >> prn >> name;
                divisionB.addPresident(prn, name);
                break;
            case 10:
                cout << "Enter PRN and Name: ";
                cin >> prn >> name;
                divisionB.addSecretary(prn, name);
                break;
            case 11:
                divisionA.concatenate(divisionB);
                cout << "Divisions concatenated!\n";
                break;
            case 12:
                divisionA.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
