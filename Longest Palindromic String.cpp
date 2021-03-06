// Longest Palindromic String

#include<bits/stdc++.h>
using namespace std;

string maxpalindrome(string s)
{
    int start = 0, n, i, j, maxlen = 1;
    string res = "";
    n = s.size();
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for(i = 0; i < n-1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            if(maxlen == 1) {
                start = i;
                maxlen = 2;
            }
        }
    }
    
    for(int k = 3; k <= n; k++) {
        for(i = 0; i < n-k+1; i++) {
            j = i+k-1;
            if(dp[i+1][j-1] && s[i] == s[j]) {
                dp[i][j] = 1;
                if(k > maxlen) {
                    maxlen = k;
                    start = i;
                }
            }
        }
    }
    
    for(i = start; i < start + maxlen; i++) {
        res = res + s[i];
    }
    
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << maxpalindrome(s) << endl;

	return 0;
}
