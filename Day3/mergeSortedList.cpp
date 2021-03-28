// done in O(1) space

// also do from GAP algo  --> todo


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=0, p2=0;
        if(m > 0 && n > 0) {
            while(p1 < m) {
                if(nums1[p1] > nums2[p2]) {
                    swap(nums1[p1], nums2[p2]);
                    sort(nums2.begin(), nums2.end());
                }
    //             1 2 3      2 5 6 
                ++p1;
            }
        }
        
        for(int i=m; i<m+n; ++i) {
            nums1[i] = nums2[i-m];
        }
    }
};
