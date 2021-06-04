// find minimum no of coins required to make amount
// demoninations are given

// using memoization
#include <bits/stdc++.h>
using namespace std;

int coinChangeUtil(vector<int> &coins, int amount, unordered_map<int, int> &memo) {

    if(memo.find(amount) != memo.end()) {
        return memo[amount];
    }
    // if amount is 0 i need 0 coins
    if(amount == 0) {
        return 0;
    }
    // if amount is less than 0 then it is not possible to make
    if(amount < 0) {
        return -1;
    }

    int minCoins = -1;

    for(int i=0; i<coins.size(); ++i) {
        int reqCoins = coinChangeUtil(coins, amount-coins[i], memo);
        // from base case when it returns (-1 or 0)
        if(reqCoins != -1) {
            // coins req to reach 0 is 1
            reqCoins += 1;
            if(minCoins == -1 || minCoins > reqCoins) {
                minCoins = reqCoins;
            }
        }
    }

    memo[amount] = minCoins;
    return minCoins;
}


int coinChange(vector<int> &coins, int amount) {
    unordered_map<int, int> memo;
    int minCoins = coinChangeUtil(coins, amount, memo);
    cout << "memo object " << endl;
    for(auto it: memo) {
        cout << it.first << " " << it.second << endl;
    }
    return minCoins;
}


int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 10;
    cout << coinChange(coins, amount);
    return 0;
}