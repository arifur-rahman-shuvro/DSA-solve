/*
Problem: Leetcode 125 - Valid Palindrome
Author: Arifur Rahman Shuvro
Date: 04 July, 2025
GitHub: https://github.com/arifur-rahman-shuvro

Description:
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:
Input: Madam
Output: true
Explanation: "Madam" → "madam", which is a palindrome.

Time Complexity: O(n)
Space Complexity: O(1) [excluding input size]
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
    inline bool alnum(char c) {
        return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    inline char to_lower(char c) {
        return (c >= 'A' && c <= 'Z') ? c + 32 : c;
    }

public:
    bool isPalindrome(const string& s) {
        const char* left = s.data();
        const char* right = s.data() + s.size() - 1;

        while (left < right) {
            while (left < right && !alnum(*left)) ++left;
            while (left < right && !alnum(*right)) --right;
            if (to_lower(*left) != to_lower(*right)) return false;
            ++left;
            --right;
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s;
    getline(cin, s);
    cout << boolalpha << sol.isPalindrome(s) << endl;
    return 0;
}
