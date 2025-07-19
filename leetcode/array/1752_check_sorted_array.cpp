/*
Problem: Leetcode 1752 - Check if Array Is Sorted and Rotated
Author: Arifur Rahman Shuvro
Date: 19 July, 2025
GitHub: https://github.com/arifur-rahman-shuvro

Description:
Given an integer array, check whether it was originally sorted in non-decreasing order and then rotated some number of times.
Return true if this condition holds, otherwise false.

Example:
Input: [3, 4, 5, 1, 2]
Output: true
Explanation: The array was sorted as [1, 2, 3, 4, 5] before being rotated to [3, 4, 5, 1, 2].

Time Complexity: O(n)
Space Complexity: O(1)
*/

//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkSorted(vector<int>& nums, int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        return count <= 1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    bool result = sol.checkSorted(nums, n);
    cout << (result ? "YES" : "NO") << endl;

    return 0;
}
