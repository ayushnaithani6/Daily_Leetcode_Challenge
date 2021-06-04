#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> prices = {5, 11, 3, 50, 60, 90};
	int k = 2;
	vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
	for(int i=1; i<k+1; ++i) {
        int maxThusFar = INT_MIN;
		for(int j=1; j<prices.size(); ++j) {
            maxThusFar = max(maxThusFar, dp[i-1][j-1]-prices[j-1]);
            dp[i][j] = max(dp[i][j-1], maxThusFar+prices[j]); 

		}
	}

	for(int i=0; i<k+1; ++i) {
        for(int j=0; j<prices.size(); ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}