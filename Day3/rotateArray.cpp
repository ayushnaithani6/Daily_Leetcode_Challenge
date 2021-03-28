class Solution {
public:
    void rotate(vector<int>& nums, int k) {
//         use reversal algorithm
        int n = nums.size();
        if(k > n) {
            k = k%n;
        }
        
        int idx = n-k;
        reverse(nums, 0, idx-1);
        reverse(nums, idx, n-1);
        reverse(nums, 0, n-1);
        
    }
    
    void reverse(vector<int> &nums, int start, int end) {
        while(start < end) {
            swap(nums[start], nums[end]);
            ++start;
            --end;
        }
    }
};
