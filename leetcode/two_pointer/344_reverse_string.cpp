/*
Problem: Leetcode 344 - Reverse String
Author: Arifur Rahman Shuvro
Date: 05 July, 2025
GitHub: https://github.com/arifur-rahman-shuvro

Description:
Write a function that reverses a string. The input string is given as a vector of characters.
You must do this by modifying the input array in-place with O(1) extra memory.

Example:
Input: ['h','e','l','l','o']
Output: ['o','l','l','e','h']

Time Complexity: O(n)
Space Complexity: O(1)
*/

//#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include<string>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = (int)s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            ++left;
            --right;
        }
    }
};

int main() {
    string s;
    getline(cin, s);
    vector<char> v(s.begin(), s.end());
    Solution sol;
    sol.reverseString(v);
    for(char c : v) cout << c;
}