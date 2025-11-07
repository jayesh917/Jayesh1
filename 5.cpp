#include <iostream>
using namespace std;

struct Node {
    int seatNo;
    bool booked;
    Node* prev;
    Node* next;

    Node(int seat) {
        seatNo = seat;
        booked = false;
        prev = next = nullptr;
    }
};

class Cinemax {
private:
    Node* rows[10];

public:
    Cinemax() {
        for (int i = 0; i < 10; i++) {
            rows[i] = nullptr;
            Node* prev = nullptr;
            for (int j = 1; j <= 7; j++) {
                Node* newNode = new Node(j);
                if (rows[i] == nullptr)
                    rows[i] = newNode;
                else {
                    prev->next = newNode;
                    newNode->prev = prev;
                }
                prev = newNode;
            }
        }
    }

    void displaySeats() {
        cout << "\nAvailable Seats (0 = Free, X = Booked):\n";
        for (int i = 0; i < 10; i++) {
            cout << "Row " << (i + 1) << ": ";
            Node* temp = rows[i];
            while (temp) {
                if (temp->booked)
                    cout << "X ";
                else
                    cout << temp->seatNo << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void bookSeat(int row, int seat) {
        if (row < 1 || row > 10 || seat < 1 || seat > 7) {
            cout << "Invalid seat selection.\n";
            return;
        }
        Node* temp = rows[row - 1];
        while (temp && temp->seatNo != seat)
            temp = temp->next;
        if (temp) {
            if (!temp->booked) {
                temp->booked = true;
                cout << "Seat " << seat << " in Row " << row << " booked successfully!\n";
            } else {
                cout << "Seat already booked.\n";
            }
        }
    }

    void cancelSeat(int row, int seat) {
        if (row < 1 || row > 10 || seat < 1 || seat > 7) {
            cout << "Invalid seat selection.\n";
            return;
        }
        Node* temp = rows[row - 1];
        while (temp && temp->seatNo != seat)
            temp = temp->next;
        if (temp) {
            if (temp->booked) {
                temp->booked = false;
                cout << "Booking for Seat " << seat << " in Row " << row << " cancelled successfully!\n";
            } else {
                cout << "Seat was not booked.\n";
            }
        }
    }
};

int main() {
    Cinemax c;
    int choice, row, seat;

    c.bookSeat(2, 3);
    c.bookSeat(5, 6);
    c.bookSeat(7, 2);

    do {
        cout << "\n--- Cinemax Ticket Booking System ---\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                c.displaySeats();
                break;
            case 2:
                cout << "Enter Row (1-10): ";
                cin >> row;
                cout << "Enter Seat (1-7): ";
                cin >> seat;
                c.bookSeat(row, seat);
                break;
            case 3:
                cout << "Enter Row (1-10): ";
                cin >> row;
                cout << "Enter Seat (1-7): ";
                cin >> seat;
                c.cancelSeat(row, seat);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
