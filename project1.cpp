#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) {     // if empty then create one
        return new Node(key);
    }
    if (key < root->key) {      // if root > key then use left
        root->left = insert(root->left, key);
    } else {       // if root < key then use right
        root->right = insert(root->right, key);
    }
    return root;
}

void inOrder(Node* root) {       // left key right
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

void preOrder(Node* root) {      // key left right
    if (root == NULL) {
        return;
    }
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {     // left right key
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << " ";
}

int sumOfNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return root->key + sumOfNodes(root->left) + sumOfNodes(root->right);
}

bool search(Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->key == key) {
        return true;
    }
    if (key > root->key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

Node* findMin(Node* root) {
    while (root->left != NULL) {        // root->left coz left has small values than root
        root = root->left;
    }
    return root;        // returns smallest root node
}

Node* remove(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    // To Find the Key 
    else if (key < root->key) {
        root->left = remove(root->left, key);
    }
    else if (key > root->key) {
        root->right = remove(root->right, key);
    }
    else {
        // When the Current Node Is Equal to Key

        // No Children
        if (root->left == NULL and root->right == NULL) {
            delete root;
            root = NULL;
        }
        // One Child
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Two Children
        else {
            Node* temp = findMin(root->right);     // finding inorder successor from right subtree

            root->key = temp->key;        // copying inorder successor to key node

            root->right = remove(root->right, temp->key);      // removing temp->key (temp is inorder successor) and the whole subtree is to right of root
        }
    }
    return root;
}

int main() {
    Node* root = NULL;
    int n, key;

    cout << "Enter the number of elements to insert: ";
    cin >> n;
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> key;
        root = insert(root, key);
    }

    cout << "Inorder Traversal gives: ";
    inOrder(root);
    cout << endl;

    cout << "PostOrder Traversal gives: ";
    postOrder(root);
    cout << endl;

    cout << "PreOrder Traversal gives: ";
    preOrder(root);
    cout << endl;

    // Searching
    cout << "Enter the key you want to search: ";
    cin >> key;
    if (search(root, key)) {
        cout << "Key is present in Tree" << endl;
    } else {
        cout << "Key is not present in Tree" << endl;
    }
    cout << endl;

    // Deletion
    cout << "Enter the key you want to delete: ";
    cin >> key;
    root = remove(root, key);

    cout << "After deletion, Inorder Traversal gives: ";
    inOrder(root);
    cout << endl;

    return 0;
}

