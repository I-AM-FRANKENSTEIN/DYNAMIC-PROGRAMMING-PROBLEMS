// Longest Palindromic Subsequence


#include <bits/stdc++.h>
using namespace std;

int max (int x, int y) { return (x > y)? x : y; } 

int longestpalindrom(string s, int l)
{
    int dp[l][l];
    for(int i = 0; i < l; i++) {
        dp[i][i] = 1;
    }
    
    for(int len = 2; len <= l; len++) {
        for(int i = 0; i < l - len + 1; i++) {
            int j = i + len - 1;
            if(s[i] == s[j]) {
                int prev = 0;
                if(len != 2) {
                    prev = dp[i+1][j-1];
                }
                dp[i][j] = 2 + prev;
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[0][l-1];
}

int main() {
	 string s;
	 cin >> s;
	 int l = s.size();
	 cout << longestpalindrom(s, l) << endl;

	return 0;
}

/*
    INPUT
    
asdabacafdsha 

    OUTPUT
9

*/
