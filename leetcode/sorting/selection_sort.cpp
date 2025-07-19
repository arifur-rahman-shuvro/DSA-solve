/* 
Problem        : Selection Sort Implementation
Author         : Arifur Rahman Shuvro
Date           : 19 July, 2025
GitHub         : https://github.com/arifur-rahman-shuvro

Description    :
Sorts an array using the selection sort algorithm.

Time Complexity  : O(n^2)
Space Complexity : O(1)

Example:
Input : [2,4,6,2,4,5]
Output: [2,2,4,4,5,6]
*/

// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void selection_sort(vector<int>& arr, int n){
        for(int i=0; i<n-1; i++){
            int min_index = i;
            for(int j=i+1; j<n; j++){
                if(arr[min_index] > arr[j]){
                    min_index = j;
                }
            }
            if(min_index != i){
                int temp = arr[i];
                arr[i] = arr[min_index];
                arr[min_index] = temp;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    Solution sol;
    sol.selection_sort(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] <<" "; 
    }
    return 0;
}
