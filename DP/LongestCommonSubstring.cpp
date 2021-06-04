#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int ans = 0;
    for(int i=1; i<m+1; ++i) {
        for(int j=1; j<n+1; ++j) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestCommonSubstring(s1, s2);
    return 0;
}
