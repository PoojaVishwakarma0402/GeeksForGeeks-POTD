// Author : Pooja Vishwakarma
// Date : 07/12/2023
// Problem : Number of subarrays with maximum values in given range
// Difficulty : Medium
// Problem Link : https://www.geeksforgeeks.org/problems/number-of-subarrays-with-maximum-values-in-given-range5949/1



class Solution {
public:
    long countSubarrays(int a[], int n, int L, int R) {
        long count = 0; // Use long to handle larger datasets
        int left = -1, right = -1;

        for (int i = 0; i < n; ++i) {
            if (a[i] >= L && a[i] <= R) {
                right = i;
                count += (right - left);
            } else if (a[i] < L) {
                count += (right - left);
            } else {
                left = i;
                right = i;
            }
        }

        return count;
    }
};
