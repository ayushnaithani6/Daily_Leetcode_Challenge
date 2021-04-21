class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
//         assuming minPossibleAns as n-1 since array can be sorted in descending order
//         then we have to remove n-1 elements (can be taken as INT_MAX) doesn't really matter
        int minPossibleAns = n-1;
        int left = 0;
        int right = n-1;
        
//         incrementing left until non decreasing subarray we are getting
//         not saying increasing because same element can be there

        
        while(left < right && arr[left] <= arr[left+1]) {
            ++left;
        }
        
//         for eg : 1, 2, 3, 10, 4, 2, 3, 5
//                            |
//                           left is here after this loop
        
        
//         array is sorted in this case (if left becomes equal to right)
        if(left == n-1) {
            return 0;
        }
        
        
//         now we do same thing but from last the intitution behind this is simply this
//         how many element we have to remove from left of the found right to make right sorted (if that make sense)
        
        while(right > left && arr[right-1] <= arr[right]) {
            --right;
        }
//         for eg : 1, 2, 3, 10, 4, 2, 3, 5
//                                  |
//                           right is here after this loop 
        

//         now we have found sorted array from left and from right
//         look elements before left are sorted
//         and after right as well
//         so what if I remove right portion of after left pointer
//         and what if I remove left portion before right pointer  
//         (if this doesnot make sense to you now just do it on paper)
        
//         we take minimum of these two
        minPossibleAns = min(n-1-left, right);
//         for above example we get min(4, 5)   ---> 4 = minPossible ans

        
        

//         it could also be possible that we remove some subarray from the mid of array
//         thankfully in this example we are getting ans form mid
        
        
//         it is basic two pointer approach i starting from 0 and j from right
//         and we basically check that if we could fit in element at left pointer before the right one
//         (if that doesnot make sense just traverse this)
        
        int j = right;
        for(int i=0; i<=left && j < n; ++i) {
            if(arr[i] <= arr[j]) {
                minPossibleAns = min(minPossibleAns, j-i-1);
            }
            else {
                ++j;
            }
         }
        
//         finally return ans
        return minPossibleAns;
    }
};




// Basic fundamental idea is we can get our ans by removing elements from starting or mid or end

// time complexity : O(n)  space is O(1)
