#include <iostream>
using namespace std;

#define MAX 5

class JobQueue {
private:
    int front, rear;
    int arr[MAX];

public:
    JobQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void addJob(int job) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more orders.\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = job;
        cout << "Order " << job << " added successfully.\n";
    }

    void deleteJob() {
        if (isEmpty()) {
            cout << "Queue is empty. No orders to serve.\n";
            return;
        }
        cout << "Order " << arr[front] << " served and removed from queue.\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Current orders in queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    JobQueue q;
    int choice, job;

    cout << "=== Pizza Parlor Job Queue Simulation ===\n";
    do {
        cout << "\n1. Add Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter order ID: ";
                cin >> job;
                q.addJob(job);
                break;
            case 2:
                q.deleteJob();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
