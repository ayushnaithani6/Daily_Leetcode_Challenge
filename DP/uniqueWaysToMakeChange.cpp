// using tabulation
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int m = coins.size()+1, n = amount+1;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int i=1; i<m; ++i) {
        dp[i][0] = 1;
    }


    for(int i=1; i<m; ++i) {
        for(int j=1; j<n; ++j) {
            if(j-coins[i-1] >= 0) {
                // two ways include ith coin or donot include it
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
            else {
                // if we include the ith coin we go negative (out of bounds)
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[m-1][n-1];
    return 0;
}