#include <bits/stdc++.h>
using namespace std;
// printing subsequence....
string LCS(string A, string B) {
    int a = A.length(), b = B.length();
    vector<vector<string>> dp(a+1, vector<string>(b+1, ""));
    
    for(int i=1; i<a+1; ++i) {
        for(int j=1; j<b+1; ++j) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1]+A[i-1];
            }
            else {
                if(dp[i-1][j].size() > dp[i][j-1].size()) {
                    dp[i][j] = dp[i-1][j];
                } 
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    return dp[a][b];
}


int main() {
    cout << LCS("xkykzpw", "zxvvyzw");
    return 0;
}