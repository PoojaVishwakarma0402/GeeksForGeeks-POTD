
// Author : Pooja Vishwakarma
// Date : 03/12/2023
// Problem : Brothers From Different Roots
// Difficulty : Easy
// Problem Link : https://www.geeksforgeeks.org/problems/brothers-from-different-root/1




class Solution {
public:
    void insertValues(Node* root, std::unordered_set<int>& values) {
        if (!root) return;

        values.insert(root->data);
        insertValues(root->left, values);
        insertValues(root->right, values);
    }

    int countPairs(Node* root1, Node* root2, int x) {
        if (!root1 || !root2) return 0;

        std::unordered_set<int> values;
        insertValues(root2, values);

        return countPairsHelper(root1, values, x);
    }

    int countPairsHelper(Node* root, std::unordered_set<int>& values, int x) {
        if (!root) return 0;

        int count = 0;
        if (values.find(x - root->data) != values.end()) {
            count++;
        }

        count += countPairsHelper(root->left, values, x);
        count += countPairsHelper(root->right, values, x);

        return count;
    }
};
