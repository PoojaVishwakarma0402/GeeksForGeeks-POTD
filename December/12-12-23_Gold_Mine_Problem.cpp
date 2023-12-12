// Author : Pooja Vishwakarma
// Date : 12/12/2023
// Problem : Gold Mine Problem
// Difficulty : Easy
// Problem Link : https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1




class Solution {
public:
    int maxGold(int n, int m, vector<vector<int>>& M) {
        if (n == 0 || m == 0) {
            return 0;
        }

        vector<vector<int>> goldTable(n, vector<int>(m, 0));

        // Copying the values from the last column to goldTable
        for (int i = 0; i < n; ++i) {
            goldTable[i][m - 1] = M[i][m - 1];
        }

        // Iterating column-wise to explore possible paths
        for (int j = m - 2; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                int maxGold = goldTable[i][j + 1]; // Move to the right

                // Move diagonally up-right
                if (i > 0) {
                    maxGold = max(maxGold, goldTable[i - 1][j + 1]);
                }

                // Move diagonally down-right
                if (i < n - 1) {
                    maxGold = max(maxGold, goldTable[i + 1][j + 1]);
                }

                // Accumulate the gold
                goldTable[i][j] = M[i][j] + maxGold;
            }
        }

        // Finding the maximum gold in the first column
        int maxGold = goldTable[0][0];
        for (int i = 1; i < n; ++i) {
            maxGold = max(maxGold, goldTable[i][0]);
        }

        return maxGold;
    }
};
