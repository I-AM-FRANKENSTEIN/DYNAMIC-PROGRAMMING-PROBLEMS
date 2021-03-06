// Word Breaking Problem


#include <bits/stdc++.h>
using namespace std;

bool containword(string word[], string str, int n)
{
    for(int i = 0; i < n; i++) {
        if(word[i].compare(str) == 0) {
            return true;
        }
    }
    
    return false;
}

bool isbreak(string word[], string s, int n) 
{
    int l = s.length();
    if(l == 0) {
        return true;
    }
    int dp[l+1];
    memset(dp, false, sizeof(dp));
    for(int i = 1; i <= l; i++) {
        if(dp[i] == false && containword(word, s.substr(0, i), n)) {
            dp[i] = true;
        }
        if(dp[i] == true) {
            if(i == l) {
                return true;
            }
            
            for(int j = i+1; j <= l; j++) {
                if(dp[j] == false && containword(word, s.substr(i, j-i), n)) {
                    dp[j] = true;
                }
                if(j == l && dp[j] == true) {
                    return true;
                }
            }
        }
    }
    
    return false;
    
}

int main() {
    int n;
    cin >> n;
    string word[n];
    for(int i = 0; i < n; i++) {
        cin >> word[i];
    }
    
    string s;
    cin >> s;
    
    if(isbreak(word, s, n)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

	return 0;
}
