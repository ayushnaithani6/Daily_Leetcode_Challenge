#include <bits/stdc++.h>
#define inf INT_MAX

using namespace std;

bool isPalindrome(string &s, int st, int en) {
    while(st < en) {
        if(s[st] != s[en]) {
            return false;
        }
        ++st;
        --en;
    }
    return true;
}


void generateTable(string &s, vector<vector<bool>> &palindrome) {
    for(int i=0; i<s.length(); ++i) {
        for(int j=i; j<s.length(); ++j) {
            if(isPalindrome(s, i, j)) {
                palindrome[i][j] = true;
            }
        }
    }
}


int minCuts(string &s) {
    int n = s.length();
    vector<vector<bool>> palindrome(n, vector<bool>(n, false));
    generateTable(s, palindrome);
    
    vector<int> dp(n, inf);
    dp[0] = 0;

    for(int i=1; i<n; ++i) {
        dp[i] = dp[i-1]+1;
        for(int j=0; j<i; ++j) {
            if(palindrome[j][i]) {
                if(j == 0) {
                    dp[i] = 0;
                    break;
                }
                dp[i] = min(dp[i], dp[j-1]+1);
            }
        }
    }

    for(int i=0; i<n; ++i) {
        cout << dp[i] << " ";
    }
    return dp[n-1];
}



int main() {
    string s = "noonabbad";
    cout << minCuts(s);
    return 0;
}