// search element in sorted rotated array
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int search(vector<int>&, int);

inline void debugMode() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	debugMode();
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; ++i) {
		cin >>a[i];
	}
	int target;
	cin >> target;
	cout << search(a, target);
	return 0;
}

int search(vector<int> &a, int target) {
	int n = a.size();
	int low = 0, high = n-1;
	while(low <= high) {
		int mid = low+(high-low)/2;

		if(a[mid] == target) {
			return mid;
		}
		else if(a[low] <= a[mid]) {
			if(target >= a[low] && target < a[mid]) {
				high = mid-1;
			}
			else {
				low = mid+1;
			}
		} 
		else {
			if(target > a[mid] && target <= a[high]) {
				low = mid+1;
			}
			else {
				high = mid-1;
			}
		}
	}
	return -1;
}
