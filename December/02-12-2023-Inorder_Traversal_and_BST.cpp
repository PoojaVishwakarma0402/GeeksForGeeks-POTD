// Author : Pooja Vishwakarma
// Date : 02/12/2023
// Problem : Inorder Traversal and BST
// Difficulty : Easy
// Problem Link : https://www.geeksforgeeks.org/problems/inorder-traversal-and-bst5855/1



class Solution {
public:
    bool isRepresentingBST(int arr[], int N) {
        // Check if the array is sorted
        for (int i = 0; i < N - 1; ++i) {
            if (arr[i] >= arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
