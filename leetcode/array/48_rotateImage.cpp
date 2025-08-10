/* 
╔══════════════════════════════════════════════════════════════════╗
║ Problem    : Leetcode 48 - Rotate Image                          ║
║ Author     : Arifur Rahman Shuvro                                ║
║ Date       : 30 July, 2025                                       ║
║ Github     : https://github.com/arifur-rahman-shuvro             ║
╚══════════════════════════════════════════════════════════════════╝

Description:

You are given an n x n 2D matrix representing an image.  
Rotate the image by 90 degrees (clockwise).  
You have to rotate the image **in-place**, which means you have to modify the input matrix directly.

Example:

Input:
matrix = [[1,2,3],
          [4,5,6],
          [7,8,9]]

Output:
[[7,4,1],
 [8,5,2],
 [9,6,3]]
*/



/*
---Brute Force---
Time Complexity: O(n²)
Space Complexity: O(n²) (for extra matrix)

Creates a new matrix to store rotated elements and returns it.


    vector<vector<int>> rotateMatrixBrute(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }
        return ans;
    }
*/

/*
---Optimal Approach: Transpose + Reverse---
 Time Complexity: O(n²)
Space Complexity: O(1)

1. Transpose the matrix (swap across diagonal)
2. Reverse each row
Rotates the matrix in-place.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    sol.rotateMatrix(matrix);

    for (const auto &row : matrix) {
        for (int val : row)
            cout << val << ' ';
        cout << '\n';
    }

    return 0;
}
