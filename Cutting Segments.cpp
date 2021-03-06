//Cutting Segements

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	int dp[n+1];
	memset(dp, -1, sizeof(dp));
	// you can use for loop in place of for loop like this
	// for(int i = 0; i <= i; i++) {
	// 	dp[i] = -1;
	
	dp[0] = 0;
	for(int i = 0; i <= n; i++) {
		if(dp[i] != -1) {
			if(i + x <= n) {
				dp[i+x] = max(dp[i]+1, dp[i+x]);
			}
			if(i + y <= n) {
				dp[i+y] = max(dp[i]+1, dp[i+y]);
			}
			if(i + z <= n) {
				dp[i+z] = max(dp[i]+1, dp[i+z]);
			}
		}
	}
	
	cout << dp[n] << endl;

	return 0;
}

/*
         INPUT  
6
2 4 3

        OUTPUT 
3


        Explanaton

(2,4), (2,2,2), (3,3)

*/
