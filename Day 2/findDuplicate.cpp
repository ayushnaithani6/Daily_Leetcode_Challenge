class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size();
        
        for(int i=0; i<n; ++i) {
            while(i+1 != a[i] && a[i] != a[a[i]-1]) {
                swap(a[i], a[a[i]-1]);
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; ++i) {
            if(i+1 != a[i]) {
                ans = a[i];
                break;
            }
        }
        
      return ans;
    }
};
