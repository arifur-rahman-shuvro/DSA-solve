/* 
╔══════════════════════════════════════════════════════════════════╗
║ Problem    : Leetcode 54 - Spiral Matrix                         ║
║ Author     : Arifur Rahman Shuvro                                ║
║ Date       : 30 July, 2025                                       ║
║ Github     : https://github.com/arifur-rahman-shuvro             ║
╚══════════════════════════════════════════════════════════════════╝

Description:

Given an m x n matrix, return all elements of the matrix in spiral order.

Illustration:

                1 → 2 → 3
                        ↓
                4 → 5   6
                ↑       ↓
                7 ← 8 ← 9 

Input:  matrix = [[1,2,3],
                  [4,5,6],
                  [7,8,9]]

Output: [1,2,3,6,9,8,7,4,5]
*/

/*
---Approach: Layer-by-layer Spiral Traversal---
Time Complexity : O(m * n)
Space Complexity: O(1) extra (excluding result array)

Use four boundaries (top, bottom, left, right) to control direction.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Solution {
public:
    vector<int> spiralMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, left = 0, right = m - 1, bottom = n - 1;
        vector<int> ans;

        while (top <= bottom && left <= right) {
            // Left to Right
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            // Top to Bottom
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            // Right to Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Bottom to Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    vector<int> result = sol.spiralMatrix(matrix);

    for (int val : result)
        cout << val << ' ';
    cout << '\n';

    return 0;
}
