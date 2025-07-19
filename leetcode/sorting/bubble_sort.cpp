/* 
Problem        : Bubble Sort Implementation
Author         : Arifur Rahman Shuvro
Date           : 19 July, 2025
GitHub         : https://github.com/arifur-rahman-shuvro

Description    :
Sorts an array using the bubble sort algorithm.

Time Complexity  : O(n^2) in worst/average, O(n) in best case (if already sorted)
Space Complexity : O(1)

Example:
Input : [5,1,4,2,8]
Output: [1,2,4,5,8]
*/

// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void bubble_sort(vector<int>& arr, int n){
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - 1 - i; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    Solution sol;
    sol.bubble_sort(arr, n);
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}
