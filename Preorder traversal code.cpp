#include <iostream>
using namespace std;

// Structure of a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a new node into the binary tree
void insert(Node*& root, int value) {
    if (root == NULL) {
        root = new Node(value);
    } else if (value < root->data) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

// Function to perform preorder traversal
void preorderTraversal(Node* node) {
    if (node == NULL) return; // Base case: if the node is null, return

    cout << node->data << " ";     // Visit the root node
    preorderTraversal(node->left);  // Traverse the left subtree
    preorderTraversal(node->right); // Traverse the right subtree
}

// Function to delete the entire binary tree
void deleteTree(Node* node) {
    if (node == NULL) return; // Base case: if the node is null, return

    deleteTree(node->left);  // Delete left subtree
    deleteTree(node->right); // Delete right subtree
    delete node;             // Delete current node
}

// Driver code
int main() {
    Node* root = NULL; // Initialize the root of the tree
    int number;

    cout << "Enter numbers to insert into the binary tree (type -1 to stop):" << endl;

    while (true) {
        cin >> number;
        if (number == -1) break; // Exit condition for input
        insert(root, number);     // Insert the number into the binary tree
    }

    cout << "Preorder traversal of the binary tree is: ";
    preorderTraversal(root); // Perform the preorder traversal
    cout << endl;

    // Clean up memory
    deleteTree(root);

    return 0;
}