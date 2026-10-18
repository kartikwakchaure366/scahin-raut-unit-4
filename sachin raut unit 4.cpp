
#include <iostream>
#include <algorithm>
using namespace std;

// Node structure
struct Node {
    int key;
    Node *left, *right;
    int height;

    Node(int value) {
        key = value;
        left = right = nullptr;
        height = 1;
    }
};

// Get height of a node
int getHeight(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Create a new node
Node* createNode(int key) {
    return new Node(key);
}

// ---------------- BST ----------------
Node* insertBST(Node* root, int key) {
    if (root == nullptr)
        return createNode(key);

    if (key < root->key)
        root->left = insertBST(root->left, key);
    else if (key > root->key)
        root->right = insertBST(root->right, key);

    return root;
}

// ---------------- AVL TREE ----------------
int getBalance(Node* node) {
    if (node == nullptr)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));
    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));
    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

// Insert into AVL tree
Node* insertAVL(Node* root, int key) {
    if (root == nullptr)
        return createNode(key);

    if (key < root->key)
        root->left = insertAVL(root->left, key);
    else if (key > root->key)
        root->right = insertAVL(root->right, key);
    else
        return root;

    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    int balance = getBalance(root);

    // Left Left case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Right Right case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Left Right case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Display search path
bool searchPath(Node* root, int key) {
    Node* current = root;

    cout << "Search path for " << key << ": ";

    while (current != nullptr) {
        cout << current->key;

        if (current->key == key) {
            cout << " (Found)" << endl;
            return true;
        }

        cout << " -> ";

        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    cout << "Not Found" << endl;
    return false;
}

// Display tree in inorder
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Main function
int main() {
    Node* bstRoot = nullptr;
    Node* avlRoot = nullptr;

    // Same sorted sequence of 15 keys
    int keys[] = {
        10, 20, 30, 40, 50,
        60, 70, 80, 90, 100,
        110, 120, 130, 140, 150
    };

    int n = sizeof(keys) / sizeof(keys[0]);

    // Insert keys into both trees
    for (int i = 0; i < n; i++) {
        bstRoot = insertBST(bstRoot, keys[i]);
        avlRoot = insertAVL(avlRoot, keys[i]);
    }

    cout << "===== BINARY SEARCH TREE (BST) =====\n";
    cout << "Inorder traversal: ";
    inorder(bstRoot);
    cout << "\nHeight: " << getHeight(bstRoot) << endl;

    cout << "\n===== AVL TREE =====\n";
    cout << "Inorder traversal: ";
    inorder(avlRoot);
    cout << "\nHeight: " << getHeight(avlRoot) << endl;

    int searchKey;
    cout << "\nEnter key to search: ";
    cin >> searchKey;

    cout << "\nBST ";
    searchPath(bstRoot, searchKey);

    cout << "AVL ";
    searchPath(avlRoot, searchKey);

    return 0;
}
