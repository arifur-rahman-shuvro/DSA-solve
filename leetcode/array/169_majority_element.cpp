/*
╔══════════════════════════════════════════════════════════════════════════════╗
║ Problem    : Leetcode 169 - Majority Elementnd                               ║
║ Author     : Arifur Rahman Shuvro                                            ║
║ Date       : 10 July, 2025                                                   ║
║ GitHub     : https://github.com/arifur-rahman-shuvro                         ║
╚══════════════════════════════════════════════════════════════════════════════╝ 
 
Description:
Given an array of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Example:
Input: [2,2,1,1,1,2,2]
Output: 2
Explanation: The number 2 appears 4 times, which is more than n/2 = 3.5

Time Complexity: O(n)
Space Complexity: O(1) [excluding input size]
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i < n; i++){
        cin>> nums[i];
    }

    Solution sol;
    cout << sol.majorityElement(nums) << endl;
}