// using memoization

#include <bits/stdc++.h>
using namespace std;

int changeUtil(vector<int> &coins, int amount, int idx, unordered_map<string, int> &memo) {
    string key = to_string(amount) + ',' + to_string(idx);
    if(memo.find(key) != memo.end()) {
        return memo[key];
    }

    if(amount == 0) {
        return 1;
    }

    if(idx == coins.size() || amount < 0) {
        return 0;
    }

    if(amount < coins[idx]) {
        memo[key] = changeUtil(coins, amount, idx+1, memo);
        return memo[key];
    }

    memo[key] = changeUtil(coins, amount-coins[idx], idx, memo) + changeUtil(coins, amount, idx+1, memo);
    return memo[key];
}




int change(vector<int> coins, int amount) {
    unordered_map<string, int> memo;
    return changeUtil(coins, amount, 0, memo);
}


int main() {
    cout << change({1, 2, 5}, 5);
}