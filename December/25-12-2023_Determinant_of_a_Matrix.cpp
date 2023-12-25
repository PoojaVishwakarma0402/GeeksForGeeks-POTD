// Author : Pooja Vishwakarma
// Date : 25/12/2023
// Problem : Determinant of a Matrix
// Difficulty : Easy
// Problem Link : https://www.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1



class Solution
{   
    public:
    // Function to get the submatrix excluding the given row and column
    vector<vector<int>> getSubMatrix(vector<vector<int>>& matrix, int row, int col, int n) {
        vector<vector<int>> sub(n - 1, vector<int>(n - 1, 0));
        int r = 0, c = 0;
        
        for (int i = 0; i < n; i++) {
            if (i != row) {
                for (int j = 0; j < n; j++) {
                    if (j != col) {
                        sub[r][c++] = matrix[i][j];
                        if (c == n - 1) {
                            r++;
                            c = 0;
                        }
                    }
                }
            }
        }
        return sub;
    }
    
    // Function to calculate determinant recursively
    int determinantOfMatrix(vector<vector<int>> matrix, int n) {
        if (n == 1) {
            return matrix[0][0];
        }
        int det = 0, sign = 1;
        
        for (int i = 0; i < n; i++) {
            vector<vector<int>> sub = getSubMatrix(matrix, 0, i, n);
            det += sign * matrix[0][i] * determinantOfMatrix(sub, n - 1);
            sign = -sign;
        }
        return det;
    }
};
