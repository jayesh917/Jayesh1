#include <iostream>
using namespace std;

// Function for Linear Search 
bool linearSearch(int arr[], int n, int key) { 
    for (int i = 0; i < n; i++) { 
        if (arr[i] == key) 
            return true; 
    } 
    return false; 
} 

// Function for Binary Search 
bool binarySearch(int arr[], int n, int key) { 
    int low = 0, high = n - 1; 
    while (low <= high) { 
        int mid = (low + high) / 2; 
        if (arr[mid] == key) 
            return true; 
        else if (arr[mid] < key) 
            low = mid + 1; 
        else 
            high = mid - 1; 
    } 
    return false; 
} 

int main() { 
    int n, key, choice; 
    cout << "Enter number of students: "; 
    cin >> n; 

    int arr[100]; // Max 100 students 
    cout << "Enter roll numbers of students:\n"; 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 

    do { 
        cout << "\n===== MENU =====\n"; 
        cout << "1. Linear Search (Random Order)\n"; 
        cout << "2. Binary Search (Sorted Order)\n"; 
        cout << "3. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 

        if (choice == 1 || choice == 2) { 
            cout << "Enter roll number to search: "; 
            cin >> key; 

            bool found = false; 
            if (choice == 1) 
                found = linearSearch(arr, n, key); 
            else if (choice == 2) 
                found = binarySearch(arr, n, key); 

            if (found) 
                cout << "Student with roll number " << key 
                     << " attended the training program.\n"; 
            else 
                cout << "Student with roll number " << key 
                     << " did NOT attend the training program.\n"; 
        } 
        else if (choice != 3) { 
            cout << "Invalid choice, please try again!\n"; 
        } 

    } while (choice != 3); 

    cout << "Exiting program...\n"; 
    return 0; 
}
