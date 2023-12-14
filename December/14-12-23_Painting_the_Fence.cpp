// Author : Pooja Vishwakarma
// Date : 14/12/2023
// Problem : Painting the Fence
// Difficulty : Medium
// Problem Link : https://www.geeksforgeeks.org/problems/painting-the-fence3727/1



class Solution {
public:
    long countways(int n, int k) {
        const long MOD = 1000000007;
        
        if (n == 1) {
            return k;
        }

        long same = 0;
        long diff = k;
        
        for (int i = 2; i <= n; i++) {
            long prevDiff = diff;
            diff = (same + diff) * (k - 1) % MOD;
            same = prevDiff;
        }

        return (same + diff) % MOD;
    }
};
