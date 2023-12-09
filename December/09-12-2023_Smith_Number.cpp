// Author : Pooja Vishwakarma
// Date : 09/12/2023
// Problem : Smith Number
// Difficulty : Medium
// Problem Link : https://www.geeksforgeeks.org/problems/smith-number4132/1


class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    vector<int> primeFactors(int num) {
        vector<int> factors;
        for (int i = 2; i * i <= num; i++) {
            while (num % i == 0) {
                factors.push_back(i);
                num /= i;
            }
        }
        if (num > 1) {
            factors.push_back(num);
        }
        return factors;
    }

    int smithNum(int n) {
        int originalDigitSum = digitSum(n);
        vector<int> factors = primeFactors(n);
        int primeFactorDigitSum = 0;
        
            // If factors are not present or the number itself is the only factor
        if (factors.empty() || factors.size() == 1 && factors[0] == n) {
           return 0; // It's a prime number, hence not a Smith number
        }
        
        for (int factor : factors) {
            primeFactorDigitSum += digitSum(factor);
        }
        return (originalDigitSum == primeFactorDigitSum);
    }
};
