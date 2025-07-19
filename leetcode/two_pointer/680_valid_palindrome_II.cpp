/*
Problem: Leetcode 680 - Valid Palindrome II
Author: Arifur Rahman Shuvro
Date: 05 July, 2025
GitHub: https://github.com/arifur-rahman-shuvro

Description:
A string 's' is given, return true if it can be a palindrome after deleting at most one character.

Example:
Input: abca
Output: true
Explanation: Removing 'c' results in "aba", which is a palindrome.

Time Complexity: O(n)
Space Complexity: O(1) [excluding input size]
*/


//#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

class Solution{
    inline bool alnum(char c){
        return (c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<= 'z');
    }
    inline char to_lower(char c){
        return (c>='A' && c<='Z') ? c+32:c;
    }
    bool check(const string& s, const char* l, const char* r){
         while(l < r){
            while(l < r && !alnum(*l)) ++l;
            while(l < r && !alnum(*r)) --r;
            if(to_lower(*l) != to_lower(*r)) return false;
            ++l;
            --r;
         }
         return true;
    }
    
    public:
    bool validPalindrome(const string& s){
        const char* left = s.data();
        const char* right = s.data() + s.size() - 1;
        while(left < right){
            while(left < right && !alnum(*left)) ++left;
            while(left < right && !alnum(*right)) --right;
            if(to_lower(*left) != to_lower(*right)) return check(s, left+1,right) || check(s,left,right-1);
            ++left;
            --right;
        }
        return true;
    }
};

int main() {
    string s;
    getline(cin, s);
    Solution sol;
    cout << boolalpha << sol.validPalindrome(s);
    
}

