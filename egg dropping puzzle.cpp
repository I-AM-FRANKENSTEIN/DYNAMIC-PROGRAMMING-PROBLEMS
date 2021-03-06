/*
Problem:
Suppose you have N eggs and you want to determine from which floor in a K-floor building 
you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts 
you need in order find the critical floor in the worst case while using the best strategy.

There are few rules given below. 
An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
*/


#include <bits/stdc++.h>
using namespace std;

int eggdropping(int egg, int fl)
{
    // 2D array (Table) for storing all possiblities.
    int dp[egg+1][fl+1];
    
    // initialize base condition when no of floor is 0 or 1;
    for(int i = 0; i <= egg; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    
    // base condition when no of egg is 1.
    for(int j = 1; j <= fl; j++) {
        dp[1][j] = j;
    }
    
    // now update all entry with the help of base conditions values.
    for(int i = 2; i <= egg; i++) {
        for(int j = 2; j <= fl; j++) {
            
            //initially dp[i][j] is infinite(maximum possible value).
            dp[i][j] = INT_MAX;
            for(int k = 1; k <= j; k++) {
                int temp = 1 + max(dp[i-1][k-1], dp[i][j-k]);
                
                // update each time if we get minimum value.
                if(temp < dp[i][j]) {
                    dp[i][j] = temp;
                }
            }
        }
    }
    
    return dp[egg][fl];
}

int main() {
    // here n = no of egg and k = no of floor
    int n, k;
    cin >> n >> k;
    
    // fuction calling of eggdropping and printing the returning value
    cout << eggdropping(n, k) << endl;
	
	return 0;
}


/*

INPUT:
2 10

OUTPUT:
4

*/
