/*
Author: Arifur Rahman Shuvro
Date: 04 July, 2025
GitHub: https://github.com/arifur-rahman-shuvro
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int firstUniqChar(const string& s) {
        int hash[26] = {0};
        for(size_t i = 0; i < s.size(); i++){
            hash[s[i] - 'a']++;
        }
        for(int i = 0; i< (int)s.size();i++){
            if(hash[s[i]-'a'] == 1) return i;
            
        }
        return -1;
        
    }
};

int main(){
    Solution sol;
    string s;
    getline(cin, s);
    cout << sol.firstUniqChar(s);
}

/*
Input: leetcode
Output: 1

Input: loveleetcode
Output: 2
*/