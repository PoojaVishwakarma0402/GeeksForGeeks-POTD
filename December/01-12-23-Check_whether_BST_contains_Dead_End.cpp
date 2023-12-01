// Author : Pooja Vishwakarma
// Date : 01/12/2023
// Problem : Check whether BST contains Dead End
// Difficulty : Easy
// Problem Link : https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1


class Solution {
public:
    bool isDeadEnd(Node* root) {
        return isDeadEndUtil(root, 1, INT_MAX);
    }

    bool isDeadEndUtil(Node* node, int minVal, int maxVal) {
        if (node == nullptr)
            return false;

        if (minVal == maxVal)
            return true;

        bool left = isDeadEndUtil(node->left, minVal, node->data - 1);
        bool right = isDeadEndUtil(node->right, node->data + 1, maxVal);

        return left || right;
    }
};
