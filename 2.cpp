#include <iostream>
using namespace std;

// Function to perform Selection Sort 
void selectionSort(float arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) { 
            if (arr[j] < arr[minIndex]) { 
                minIndex = j; 
            } 
        } 
        // Swap 
        float temp = arr[i]; 
        arr[i] = arr[minIndex]; 
        arr[minIndex] = temp; 
    } 
} 

// Function to perform Bubble Sort 
void bubbleSort(float arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                // Swap 
                float temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
} 

// Function to display top 5 scores 
void displayTopFive(float arr[], int n) { 
    cout << "\nTop 5 Scores are:\n"; 
    int count = 0; 
    for (int i = n - 1; i >= 0 && count < 5; i--) { 
        cout << arr[i] << " "; 
        count++; 
    } 
    cout << endl; 
} 

int main() { 
    int n; 
    cout << "Enter number of students: "; 
    cin >> n; 

    float percentages[100];  // Array to store percentages 
    cout << "Enter percentages of students:\n"; 
    for (int i = 0; i < n; i++) { 
        cin >> percentages[i]; 
    } 

    int choice; 
    cout << "\nChoose Sorting Method:\n"; 
    cout << "1. Selection Sort\n2. Bubble Sort\nEnter choice: "; 
    cin >> choice; 

    if (choice == 1) { 
        selectionSort(percentages, n); 
        cout << "\nArray sorted using Selection Sort.\n"; 
    } else if (choice == 2) { 
        bubbleSort(percentages, n); 
        cout << "\nArray sorted using Bubble Sort.\n"; 
    } else { 
        cout << "Invalid choice!" << endl; 
        return 0; 
    } 

    // Display sorted percentages 
    cout << "\nSorted Percentages:\n"; 
    for (int i = 0; i < n; i++) { 
        cout << percentages[i] << " "; 
    } 
    cout << endl; 

    // Display top 5 scores 
    displayTopFive(percentages, n); 

    return 0; 
}
