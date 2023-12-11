// Author : Pooja Vishwakarma
// Date : 11/12/2023
// Problem : Max Sum Subarray of size K
// Difficulty : Easy
// Problem Link : https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1



class Solution{   
public:
long maximumSumSubarray(int k, vector<int> &arr, int n) {
    long maxSum = 0;
    long currentSum = 0;

    // Calculate sum of the first window of size k
    for (int i = 0; i < k; ++i) {
        maxSum += arr[i];
    }

    currentSum = maxSum;

    // Find the maximum sum of k-sized subarray using Kadane's algorithm
    for (int i = k; i < n; ++i) {
        currentSum += arr[i] - arr[i - k]; // Slide the window by adding next element and removing first element
        maxSum = max(maxSum, currentSum);
        // Ensure that currentSum doesn't go below 0 as Kadane's algorithm
        // If it becomes negative, reset currentSum to 0
        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum;
}

};
