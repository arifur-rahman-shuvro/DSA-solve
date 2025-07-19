/*
Problem: Remove Duplicates from Sorted Array (Leetcode style)
Author: Arifur Rahman Shuvro
Date: 19 July, 2025
GitHub: https://github.com/arifur-rahman-shuvro

Description:
Given a sorted array nums, remove the duplicates in-place such that each element appears only once 
and return the new length. The relative order of the elements should be kept the same. 
It doesn't matter what values are set beyond the returned length.

Example:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]

Time Complexity: O(n)
Space Complexity: O(1)
*/

//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicate(vector<int>& nums, int n) {
        if (n == 0) return 0;
        
        int k = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
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
    int newLength = sol.removeDuplicate(nums, n);

    cout << "New length: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
