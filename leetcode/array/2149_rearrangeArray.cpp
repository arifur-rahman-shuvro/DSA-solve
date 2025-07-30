/* 
╔════════════════════════════════════════════════════════════════════╗
║ Problem    : Leetcode 2149 - Rearrange Array Elements by Sign      ║
║ Author     : Arifur Rahman Shuvro                                  ║
║ Date       : 30 July, 2025                                         ║
║ Github     : https://github.com/arifur-rahman-shuvro               ║
╚════════════════════════════════════════════════════════════════════╝

Description:

You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned condition

Example:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]

Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions. 
*/


/*
--------------------
Brute Force Approach
--------------------

// Time Complexity : O(n)  
// Space Complexity: O(n)

// 1. Create separate vectors for positive and negative values.
// 2. Merge them in alternating positions.

class BruteSolution {
public:
    vector<int> rearrangeArrayBrute(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }

        for (int i = 0; i < n / 2; i++) {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
        }

        return nums;
    }
};
*/

/*
------------------------------------
Optimal Approach (using extra array)
------------------------------------

Time Complexity : O(n)  
Space Complexity: O(n)

1. Use two pointers: one for even indices (positive), one for odd (negative)
2. Directly place values into correct positions
*/

//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int posIdx = 0, negIdx = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result[posIdx] = nums[i];
                posIdx += 2;
            } else {
                result[negIdx] = nums[i];
                negIdx += 2;
            }
        }

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> result = sol.rearrangeArray(nums);

    for (int val : result)
        cout << val << ' ';
    cout << '\n';

    return 0;
}
