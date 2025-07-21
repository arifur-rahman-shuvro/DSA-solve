/*
╔══════════════════════════════════════════════════════════════════╗
║ Problem    : Leetcode 53 - Maximum Subarray                      ║
║ Author     : Arifur Rahman Shuvro                                ║
║ Date       : 21 July, 2025                                       ║
║ Github     : https://github.com/arifur-rahman-shuvro     ║
╚══════════════════════════════════════════════════════════════════╝

Description:

Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/


/*
---Brute Force---

for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
        int sum = 0;
        for(int k=i; k<=j; k++){
            sum += nums[k];
        }
        if(sum > max1){
            maxi = sum;
        }
    }
}

Time Complexity: O(n^3)
Space Complexity: O(1)

*/

/*
---Better Approach---

for(int i=0; i<n; i++){
    int sum = 0;
    for(int j=i; j<n; j++){
        sum += nums[j];
        if(sum > max1){
            maxi = sum;
        }
    }
}

Time Complexity: O(n^2)
Space Complexity: O(1)

*/

/*
---Optimized: Kadane's Algorithm---
Time Complexity: O(n)
Space Complexity: O(1)
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    long long maxSum(vector<int>& nums){
        int n = nums.size();
        long long sum = 0;
        long long maxi = LLONG_MIN;
        for(int i=0; i<n; i++){
           sum += nums[i];
           if(sum > maxi){
               maxi = sum;
           }
           if(sum < 0){
               sum = 0;
           }
        }
        return maxi;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    Solution sol;
    cout << sol.maxSum(nums);
    return 0;
}

/*
if want to print the subarray

int start = 0, 
end = 0, 
tempStart = 0;
long long sum = 0, 
maxi = LLONG_MIN;

for (int i = 0; i < n; i++) {
    sum += nums[i];
    if (sum > maxi) {
        maxi = sum;
        start = tempStart;
        end = i;
    }
    if (sum < 0) {
        sum = 0;
        tempStart = i + 1;
    }
}
*/