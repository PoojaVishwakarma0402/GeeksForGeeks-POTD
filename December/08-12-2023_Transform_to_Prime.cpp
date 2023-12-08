// Author : Pooja Vishwakarma
// Date : 08/12/2023
// Problem : Transform to Prime
// Difficulty : Medium
// Problem Link : https://www.geeksforgeeks.org/problems/transform-to-prime4635/1


class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false; // Not a prime number if divisible by any number other than 1 and itself
            }
        }
        return true; // If no divisors found, it's a prime number
    }

    int minNumber(int arr[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        int count = 0;
        while (!isPrime(sum)) {
            sum++; // Increment the sum
            count++; // Increment count of numbers added
        }

        return count;
    }
};
