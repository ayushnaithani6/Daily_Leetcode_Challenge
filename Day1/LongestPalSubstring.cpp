class Solution {
public:
//     O(n^2) approach
    string longestPalindrome(string s) {
//         single char is always palindrome  
//         {0, 1} is excluding 1
        vector<int> currentLongest = {0, 1};
        
        for(int i=1; i<s.size(); ++i) {
//             abcba  odd len palindrome
//            <--^-->  expand towards left and right   
            vector<int> odd = checkLenAtPoint(s, i-1, i+1);
//             aa|aa   (this is point of sepration in the mid)
//             traverse baadb for more clarity
            vector<int> even = checkLenAtPoint(s, i-1, i);
            
//             taking maximum length of palindrome and comparing it to
//             current Longest
            
            int oddLen = odd[1]-odd[0];
            int evenLen = even[1]-even[0];
            
            vector<int> maxAtThatPoint = (oddLen > evenLen) ? odd : even;
            
            int maxLenAtThatPoint = maxAtThatPoint[1] - maxAtThatPoint[0];
            int curLongest = currentLongest[1] - currentLongest[0];
            
            currentLongest = (curLongest > maxLenAtThatPoint) ? currentLongest : maxAtThatPoint; 
        }
        
        return s.substr(currentLongest[0], currentLongest[1]-currentLongest[0]);
    }
    
    vector<int> checkLenAtPoint(string &s, int left, int right) {
        while(left >= 0 && right < s.size()) {
            if(s[left] != s[right]) {
                break;
            }
            --left;
            ++right;
        }
        
        return {left+1, right};
    }
};
