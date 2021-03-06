
/*
Given a positive integer N, count all possible distinct binary strings of length N 
such that there are no consecutive 1’s. Output your answer mod 10^9 + 7.
*/


#include <iostream>
using namespace std;

int possibleStrings(int n)
{
    int m = 1000000007;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 2;
    int zero = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + zero) % m;
        zero = dp[i-1];
    }
    
    return dp[n];
}

int main() {
    
    int n;
    cin >> n;
    
    cout << possibleStrings(n) << endl;

	return 0;
}

/*
INPUT:
18

OUTPUT:
6765
*/
