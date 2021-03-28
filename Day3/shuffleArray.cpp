class Solution {
public:
//     knuth shuffle algorithm

//     Basic shuffle algo : iterate from right to left and select a random 
//     index less than ith index and swap
    vector<int> original;
    vector<int> shuffled;
    Solution(vector<int>& nums) {
        original = nums;
        shuffled = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=shuffled.size()-1; i>=0; --i) {
            swap(shuffled[i], shuffled[rand()%(i+1)]);
        }
        
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
