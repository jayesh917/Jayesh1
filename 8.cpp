#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int height(Node* root) {
    if (!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root ? root->data : -1;
}

void mirror(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

bool search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Enter value to insert: ";
    cin >> val;
    root = insert(root, val);

    cout << "Height (nodes): " << height(root) << "\n";
    cout << "Minimum value: " << findMin(root) << "\n";

    mirror(root);
    cout << "Inorder after mirror: ";
    inorder(root);
    cout << "\n";

    cout << "Enter value to search: ";
    cin >> val;
    cout << (search(root, val) ? "Found\n" : "Not Found\n");

    return 0;
}
