/*
╔══════════════════════════════════════════════════════════════════════════════╗
║ Problem    : Print sum of N to M                                             ║
║ Author     : Arifur Rahman Shuvro                                            ║
║ Credit     : Concept learned from "A2Z Striver" Playlist                     ║
║ Date       : 02 July, 2025 (Repo Changed)                                    ║
║ GitHub     : https://github.com/arifur-rahman-shuvro                         ║
╚══════════════════════════════════════════════════════════════════════════════╝
*/

/*
Description: 
Recursion is used instead of a loop to get sum of n to m (inclusive).
*/

#include <iostream>
using namespace std;

// Recursive function to print numbers from n to m
int sum_n_to_m(int n, int m) {
    if (n > m) return 0;       // Base case: if n exceeds m, stop recursion
    return n + sum_n_to_m(n + 1, m);  // Recursive call with n incremented
    
}

int main() {
    int n; // Start point
    int m; // End point
    cin >> n >> m;
    cout << sum_n_to_m(n, m);
    return 0;
}

/*
Input:
1 10

Output: 55
*/