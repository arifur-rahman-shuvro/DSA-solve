/*
╔══════════════════════════════════════════════════════════════════╗
║ Problem    : Leetcode 75 - Sort colors                           ║
║ Author     : Arifur Rahman Shuvro                                ║
║ Date       : 21 July, 2025                                       ║
║ Github     : https://github.com/arifur-rahman-shuvro             ║
╚══════════════════════════════════════════════════════════════════╝

Description:

Given an array nums with n objects colored red (0), white (1), and blue (2),
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.
No library sort function allowed

Example:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

/*
---Brute Force: Merge Sort---
[https://github.com/arifur-rahman-shuvro/DSA-solve/blob/main/leetcode/sorting/merge_sort.cpp]
Time Complexity: O(n log n)
Space Complexity: O(n)

/*
---Better Approach---
Time Complexity: O(2n)
Space Complexity: O(1)

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) count0++;
        else if (nums[i] == 1) count1++;
        else count2++;
    }
    for (int i = 0; i < count0; i++) nums[i] = 0;
    for (int i = count0; i < count0 + count1; i++) nums[i] = 1;
    for (int i = count0 + count1; i < n; i++) nums[i] = 2;
*/

/*
---Optimized Approach: Dutch National Flag Algorithm---
Time Complexity: O(n)
Space Complexity: O(1)
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Solution {
public:
    void color_sort(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                ++mid;
                ++low;
            }
            else if (nums[mid] == 1) {
                ++mid;
            }
            else { 
                swap(nums[mid], nums[high]);
                --high;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    try {
        int n;
        if (!(cin >> n) || n < 0)
            throw invalid_argument("Invalid input for array size.");

        vector<int> nums(n);
        for (auto &num : nums) {
            if (!(cin >> num))
                throw invalid_argument("Invalid input for array element.");
            if (num < 0 || num > 2)
                throw out_of_range("Array elements must be 0, 1, or 2.");
        }

        Solution sol;
        sol.color_sort(nums);

        for (const auto &num : nums)
            cout << num << ' ';
        cout << '\n';
    }
    catch (const exception &ex) {
        cerr << "Error: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}
