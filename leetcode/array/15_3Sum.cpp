/* 
╔══════════════════════════════════════════════════════════════════╗
║ Problem    : Leetcode 15 - 3Sum                                  ║
║ Author     : Arifur Rahman Shuvro                                ║
║ Date       : 30 July, 2025                                       ║
║ Github     : https://github.com/arifur-rahman-shuvro             ║
╚══════════════════════════════════════════════════════════════════╝

Description:

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/

/*
---Brute Force---
Time Complexity: O(n³)
Space Complexity: O(n) for set to store unique triplets

    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
*/

/*
---Better Approach---
Time Complexity: O(n²)
Space Complexity: O(n) for set and unordered_set

    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        unordered_set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            int third = - (nums[i] + nums[j]);
            if (hashset.count(third)) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
*/

/*
---Optimal Approach: Two Pointers + Sorting---
Time Complexity: O(n²)
Space Complexity: O(1) excluding output space

Sort the array, and for each element, use two pointers to find valid pairs.
Skip duplicates to avoid repeated triplets.
*/

//include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) j++;
                else if (sum > 0) k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    try {
        int n;
        if (!(cin >> n) || n < 3)
            throw invalid_argument("Array size must be at least 3.");

        vector<int> nums(n);
        for (auto &num : nums) {
            if (!(cin >> num))
                throw invalid_argument("Invalid input for array element.");
        }

        Solution sol;
        vector<vector<int>> result = sol.threeSum(nums);

        for (const auto &triplet : result) {
            for (const auto &num : triplet)
                cout << num << ' ';
            cout << '\n';
        }
    }
    catch (const exception &ex) {
        cerr << "Error: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}
