class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        for(int i=0; i<nums2.size(); ++i) {
            count[nums2[i]] += 1;
        }
        
        int p1=0;
        for(int i=0; i<nums1.size(); ++i) {
            if(count[nums1[i]] != 0) {
                 --count[nums1[i]];
                swap(nums1[p1], nums1[i]);
                ++p1;
            }
        }
        
        
        nums1.assign(nums1.begin(), nums1.begin()+p1);
        return nums1;
    }
};
