#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insertRec(root, val);
    }

    void deleteNode(int val) {
        root = deleteRec(root, val);
    }

    bool search(int val) {
        return searchRec(root, val);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        postorderRec(root);
        cout << endl;
    }

private:
    Node* root;

    Node* insertRec(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else if (val > node->data) {
            node->right = insertRec(node->right, val);
        }
        return node;
    }

    Node* deleteRec(Node* node, int val) {
        if (node == nullptr) return node;

        if (val < node->data) {
            node->left = deleteRec(node->left, val);
        } else if (val > node->data) {
            node->right = deleteRec(node->right, val);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    bool searchRec(Node* node, int val) {
        if (node == nullptr) return false;
        if (node->data == val) return true;
        if (val < node->data) return searchRec(node->left, val);
        return searchRec(node->right, val);
    }

    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    void preorderRec(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    void postorderRec(Node* node) {
        if (node != nullptr) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " ";
        }
    }
};

int main() {
    BST tree;
    int choice = 1;
    int value;

    while (choice != 0) {
        cout << "Binary Search Tree Operations:" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Search element" << endl;
        cout << "4. Inorder traversal" << endl;
        cout << "5. Preorder traversal" << endl;
        cout << "6. Postorder traversal" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Enter value to be deleted: ";
                cin >> value;
                tree.deleteNode(value);
                break;
            case 3:
                cout << "Enter value to be searched: ";
                cin >> value;
                if (tree.search(value)) {
                    cout << value << " is found in the tree." << endl;
                } else {
                    cout << value << " is not found in the tree." << endl;
                }
                break;
            case 4:
                cout << "Inorder traversal: ";
                tree.inorder();
                break;
            case 5:
                cout << "Preorder traversal: ";
                tree.preorder();
                break;
            case 6:
                cout << "Postorder traversal: ";
                tree.postorder();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
        cout << endl;
    }

    return 0;
}
