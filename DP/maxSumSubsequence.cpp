//  max sum subsequence 
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> nums = {8, 12, 2, 3, 15, 5, 7};
    int n = nums.size();
    vector<int> dp(n, 0);
    vector<int> path(n, -1);

    dp[0] = nums[0];
    int maxSum = max(0, nums[0]);
    int idx = 0;
    
    for(int i=1; i<n; ++i) {
        dp[i] = nums[i];
        for(int j=0; j<i; ++j) {
            if(nums[j] < nums[i] && dp[i] < dp[j]+nums[i]) {
                dp[i] = dp[j] + nums[i];
                if(maxSum < dp[i]) {
                    maxSum = dp[i];
                    idx = i;
                }
                path[i] = j;
            }
        }
    }

    cout << maxSum << endl;
    
    cout << "path is : " << " ";
    while(idx != -1) {
        cout << nums[idx] << " ";
        idx = path[idx];
    }

    return 0;
}