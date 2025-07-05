/*
Problem: Leetcode 387 - First Unique Character in a String
Author: Arifur Rahman Shuvro
Date: 04 July, 2025
GitHub: https://github.com/arifur-rahman-shuvro

Description:
Given a string s, return the index of the first non-repeating character.
If no such character exists, return -1.

Examples:
Input: leetcode
Output: 0

Input: loveleetcode
Output: 2

Time Complexity: O(n)
Space Complexity: O(1) [Fixed 26-char array]
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(const string& s) {
        int hash[26] = {0};
        for (size_t i = 0; i < s.size(); ++i) {
            hash[s[i] - 'a']++;
        }

        for (int i = 0; i < (int)s.size(); ++i) {
            if (hash[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    string s;
    getline(cin, s);
    cout << sol.firstUniqChar(s) << endl;
    return 0;
}
