// Author : Pooja Vishwakarma
// Date : 13/12/2023
// Problem : Consecutive 1's not allowed
// Difficulty : Medium
// Problem Link : https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1


#define MOD 1000000007

class Solution{
public:
    long long countStrings(int n) {
        long long endingWithZero = 1, endingWithOne = 1;

        for (int i = 2; i <= n; ++i) {
            long long temp = endingWithZero;
            endingWithZero = (endingWithZero + endingWithOne) % MOD;
            endingWithOne = temp;
        }

        return (endingWithZero + endingWithOne) % MOD;
    }
};
