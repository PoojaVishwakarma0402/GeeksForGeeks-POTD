// Author : Pooja Vishwakarma
// Date : 06/12/2023
// Problem : How Many X's?
// Difficulty : Medium
// Problem Link : https://www.geeksforgeeks.org/problems/how-many-xs4514/1




class Solution {
  public:
    
    int countX(int L, int R, int X) {
       int count = 0;

       for (int num = L + 1; num < R; ++num) {
           int temp = num;

        // Count occurrences of digit X in the current number
           while (temp > 0) {
               if (temp % 10 == X) {
                   ++count;
               }
               temp /= 10;
            }
       }

       return count;
    }

};
