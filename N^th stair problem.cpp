/*
Problem:
There are N stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top
*/

#include <iostream>
using namespace std;

int lastStair(int n) 
{
    int dp[n+1];
    int m = 1000000007;
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % m;
    }
    
    return dp[n];
}

int main() {
    
    // n = number of stairs
    int n;
    cin >> n;
    
    // fuction to find no of way to reach nth stair
    // for more then 1 test case you can use a globe array dp and update it once.
    // and use it for multiple test cases for reducing time complexity.
    cout << lastStair(n) << endl;

	return 0;
}


/*
INPUT:
24

OUTPUT:
75025
*/
