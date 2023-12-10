// Author : Pooja Vishwakarma
// Date : 10/12/2023
// Problem : Subarray with sum 0
// Difficulty : Medium
// Problem Link : https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1


//Function to check whether there is a subarray present with 0-sum or not.
bool subArrayExists(int arr[], int n) {
    unordered_set<int> prefixSums;
    int currentSum = 0;

    for (int i = 0; i < n; ++i) {
        currentSum += arr[i];

        // If the current sum is zero or it has been seen before,
        // it means a subarray with a sum of zero exists.
        if (currentSum == 0 || prefixSums.find(currentSum) != prefixSums.end()) {
            return true;
        }

        prefixSums.insert(currentSum);
    }

    return false;
}
