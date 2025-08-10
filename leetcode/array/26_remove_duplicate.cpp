/*
╔══════════════════════════════════════════════════════════════════╗
║ Problem    : Remove Duplicates from Sorted Array (Leetcode style)║
║ Author     : Arifur Rahman Shuvro                                ║
║ Date       : 19 July, 2025                                       ║
║ Github     : https://github.com/arifur-rahman-shuvro             ║
╚══════════════════════════════════════════════════════════════════╝

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

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
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
    std::vector<int> nums = {1,1,2};
    Solution sol;
    int len = sol.removeDuplicates(nums);

    std::cout << "New length: " << len << "\nArray: ";
    for (int i = 0; i < len; ++i) std::cout << nums[i] << " ";
    std::cout << "\n";
    return 0;
}
