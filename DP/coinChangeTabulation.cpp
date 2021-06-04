#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 10;

    // step1 : initialize the table
    vector<int> dp(amount+1, -1);
    // step2 : seed the table (base value which we know)
    // like : if we have 0 amount 0 coins are req
    dp[0] = 0;

    for(int i=0; i<amount+1; ++i) {
        if(dp[i] == -1) {
            continue;
        }

        for(int j=0; j<coins.size(); ++j) {
            if(i+coins[j] < amount+1) {
                if(dp[i+coins[j]] == -1 || dp[i+coins[j]] > dp[i]+1) {
                    dp[i+coins[j]] = dp[i] + 1;
                }
            }
        }
    }

    cout << dp[amount];
    return 0;   
}