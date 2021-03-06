/*
Problem:
Given a value N, find the number of ways to make change for N cents, 
if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. 
The order of coins doesn’t matter. 
*/

#include <bits/stdc++.h>
using namespace std;

int numberOfWay(int arr[], int m, int n) 
{
    // declaration of 2D matrix for storing value as table.
    int dp[m][n+1];
    
    // initialization base condition for dynamic programing
    for(int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    
    // calculate all posible values.
    for(int i = 0; i < m; i++) {
        for(int j = 1; j <= n; j++) {
            int x = 0;
            int y = 0;
            if(j >= arr[i]) {
                y = dp[i][j - arr[i]];
            } 
            if(i > 0) {
                x = dp[i-1][j];
            }
            dp[i][j] = x + y;
        }
    }
    
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     } 
    //     cout << endl;
    // }
    
    // return last entry of table.
    return dp[m-1][n];
}

int main() {
    
    // m is the no of coins and n is the value which we need to change in coins
    int m, n;
    cin >> m;
    
    // Array to store all coins
    int arr[m];
    for(int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    cin >> n;
    
    // Sort all coins in increasing order so we can solve it easily we will get same result without sorting.
    sort(arr, arr+m);  // Optional we can get same resutl without it.
    
    // Function calling for finding maximum no of ways.
    cout << numberOfWay(arr, m, n) << endl;
	    
	return 0;
}


/*
INPUT:
4
1 2 3  5
10

OUTPUT:
20


*/
