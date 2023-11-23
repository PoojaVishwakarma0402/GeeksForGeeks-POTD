// Author : Pooja Vishwakarma
// Date : 23/11/2023
// Problem : AVL Tree Insertion
// Difficulty : Hard
// Problem Link : https://www.geeksforgeeks.org/problems/avl-tree-insertion/1


class Solution {
public:
    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* insertToAVL(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insertToAVL(node->left, data);
        } else if (data > node->data) {
            node->right = insertToAVL(node->right, data);
        } else {
            // Duplicate data not allowed in AVL, handle if required
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Perform rotations if balance is violated
        if (balance > 1 && data < node->left->data) {
            return rightRotate(node);
        }

        if (balance < -1 && data > node->right->data) {
            return leftRotate(node);
        }

        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
};
