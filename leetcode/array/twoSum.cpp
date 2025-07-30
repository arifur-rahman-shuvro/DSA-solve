/* 
╔══════════════════════════════════════════════════════════════════╗
║ Problem    : Leetcode 1 - Two Sum                                ║
║ Author     : Arifur Rahman Shuvro                                ║
║ Date       : 30 July, 2025                                       ║
║ Github     : https://github.com/arifur-rahman-shuvro             ║
╚══════════════════════════════════════════════════════════════════╝

Description:

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]
*/

/*
---Brute Force---
Time Complexity: O(n²)
Space Complexity: O(1)

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
*/

/*
---Optimized Approach: Hash Map---
Time Complexity: O(n)
Space Complexity: O(n)
Uses a single-pass hash table to store complements and indices.
*/

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mpp.find(need) != mpp.end()) {
                return {mpp[need], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    try {
        int n, target;
        if (!(cin >> n) || n < 2)
            throw invalid_argument("Invalid input for array size (must be >= 2).");

        vector<int> nums(n);
        for (auto &num : nums) {
            if (!(cin >> num))
                throw invalid_argument("Invalid input for array element.");
        }

        if (!(cin >> target))
            throw invalid_argument("Invalid input for target.");

        Solution sol;
        vector<int> result = sol.twoSum(nums, target);

        if (result.empty()) {
            cout << "No valid pair found.\n";
        } else {
            for (const auto &idx : result)
                cout << idx << ' ';
            cout << '\n';
        }
    }
    catch (const exception &ex) {
        cerr << "Error: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}
