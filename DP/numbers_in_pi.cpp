// time complexity : O(n^3+m)
// space complexity : O(n+m)
// n = pi.length()  m = s.size()

#include <bits/stdc++.h>
using namespace std;

int getMinSpaces(string&, unordered_map<string, bool>&, unordered_map<int, int> &, int);

int main() {
    string pi = "3141592";
    vector<string> s = {"3141", "5", "31", "2", "4159", "9", "42"};
    int idx = 0;
    unordered_map<string, bool> nums;
    unordered_map<int, int> memo;

    for(int i=0; i<s.size(); ++i) {
        nums[s[i]] = true;
    }

    int minSpaces = getMinSpaces(pi, nums, memo, idx);
    cout << minSpaces;
    return 0;
}


int getMinSpaces(string &pi, unordered_map<string, bool> &nums, unordered_map<int, int> &memo, int idx) {
    if(idx == pi.length()) {
        return -1;
    }

    if(memo.find(idx) != memo.end()) {
        return memo[idx];
    }

    int minSpaces = INT_MAX;
    for(int i=idx; i<pi.length(); ++i) {
        string prefix = pi.substr(idx, i-idx+1);
        cout << prefix << endl;
        if(nums.find(prefix) != nums.end()) {
            int minSpacesInSuffix = getMinSpaces(pi, nums, memo, i+1);
            minSpaces = min(minSpaces, minSpacesInSuffix+1);
        }
    }

    memo[idx] = minSpaces;
    return minSpaces;
}