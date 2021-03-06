/*
Problem:
Given a sequence A of size N, find the length of the longest increasing subsequence from a given sequence.
*/

#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    int maxlength = 0;
    int dp[n];
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(dp[i] > maxlength) {
            maxlength = dp[i];
        }
    }
    
    return maxlength;
}

int main() {
    
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << longestIncreasingSubsequence(arr, n) << endl;
	
	return 0;
}

/*
INPUT:
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15

OUTPUT:
6
*/
