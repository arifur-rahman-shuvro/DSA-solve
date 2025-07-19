/* 
Problem        : Insertion Sort Implementation
Author         : Arifur Rahman Shuvro
Date           : 19 July, 2025
GitHub         : https://github.com/arifur-rahman-shuvro

Description    :
Sorts an array using the insertion sort algorithm.

Time Complexity  : O(n^2)
Space Complexity : O(1)

Example:
Input : [5, 3, 2, 4, 1]
Output: [1, 2, 3, 4, 5]
*/
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void insertion_sort(vector<int>& arr, int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    sol.insertion_sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
