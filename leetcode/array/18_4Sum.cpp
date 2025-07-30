/* 
╔══════════════════════════════════════════════════════════════════╗
║ Problem    : Leetcode 18 - 4Sum                                  ║
║ Author     : Arifur Rahman Shuvro                                ║
║ Date       : 30 July, 2025                                       ║
║ Github     : https://github.com/arifur-rahman-shuvro             ║
╚══════════════════════════════════════════════════════════════════╝

Description:

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    1.0 <= a, b, c, d < n
    2.a, b, c, and d are distinct.
    3.nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]
*/

/*
---Brute Force---
Time Complexity: O(n⁴)
Space Complexity: O(n) for set

    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
*/

/*
---Better Approach---
Time Complexity: O(n³)
Space Complexity: O(n) for inner set

    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                int fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
*/

/*
---Optimal Approach: Two Pointers + Sorting---
Time Complexity: O(n³)
Space Complexity: O(1) (excluding output space)

Sort the array, fix two pointers, and use two more (k, l) for checking sums.
Avoid duplicates with skip conditions.
*/

//include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum < target) k++;
                    else if (sum > target) l--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
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
        int n, target;
        if (!(cin >> n) || n < 4)
            throw invalid_argument("Array size must be at least 4.");

        vector<int> nums(n);
        for (auto &num : nums) {
            if (!(cin >> num))
                throw invalid_argument("Invalid input for array element.");
        }

        if (!(cin >> target))
            throw invalid_argument("Invalid input for target.");

        Solution sol;
        vector<vector<int>> result = sol.fourSum(nums, target);

        for (const auto &quad : result) {
            for (const auto &num : quad)
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
