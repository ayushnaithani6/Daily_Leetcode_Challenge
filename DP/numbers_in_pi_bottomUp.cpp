#include <bits/stdc++.h>
using namespace std;

int getMinSpaces(string &pi, unordered_map<string, bool> &nums, unordered_map<int, int> &memo, int idx) {
    if(idx == pi.size()) {
        return -1;
    }

    if(memo.find(idx) != memo.end()) {
        return memo[idx];
    }

    int minSpaces = INT_MAX;
    for(int i=idx; i<pi.size(); ++i) {
        string prefix = pi.substr(idx, i-idx+1);
        if(nums.find(prefix) != nums.end()) {
            int minSpacesInSuffix = getMinSpaces(pi, nums, memo, i+1);
            minSpaces = min(minSpaces, minSpacesInSuffix+1);
        }
    }

    memo[idx] = minSpaces;
    return minSpaces;
}

int main() {
    string pi = "3141592";
    vector<string> s = {"3141", "5", "31", "2", "4159", "9", "42"};
    int idx = 0;
    unordered_map<string, bool> nums;
    unordered_map<int, int> memo;

    for(int i=0; i<s.size(); ++i) {
        nums[s[i]] = true;
    }

    for(int i=pi.length()-1; i>=0; --i) 
        getMinSpaces(pi, nums, memo, idx);
    cout << memo[0];
    return 0;
}