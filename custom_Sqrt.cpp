// sqrt function using binary search

#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int low = 0, high = n;
	int mid = 0;

	while(low <= high) {
		mid = low+(high-low)/2;
		if(mid*mid == n) {
			break;
		}
		else if(mid*mid > n) {
			high = mid-1;
		}
		else {
			low = mid+1;
		}
	}


	float p = 0.1f;
	float ans = mid;
	for(int i=0; i<5; ++i) {
		while(ans*ans <= n) {
			ans += p;
		}
		ans -= p;
		p /= 10;
	}

	cout << ans;
	return 0;
}
