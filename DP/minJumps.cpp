#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> nums = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3};
    vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;

    for(int i=1; i<nums.size(); ++i) {
        for(int j=0; j<i; ++j) {
            if(j+nums[j] >= i && dp[i] > dp[j]+1) {
                dp[i] = dp[j]+1;
            }
        }
    }

    cout << dp[nums.size()-1];
    return 0;
}