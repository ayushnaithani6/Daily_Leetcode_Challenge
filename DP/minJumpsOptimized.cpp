#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> nums = {3, 4, 2, 1, 2, 3, 4, 1, 1, 1, 3};
    if(nums.size() == 1) {
        cout << 0;
        return 0;
    }

    int steps = nums[0];
    int maxReach = nums[0];
    int jumps = 0;
    for(int i=1; i<nums.size(); ++i) {
        if(i == nums.size()-1) {
            break;
        }
        maxReach = max(maxReach, nums[i]+i);
        --steps;
        if(steps == 0) {
            ++jumps;
            steps = maxReach-i;
        }
    }
    cout << jumps+1;
}