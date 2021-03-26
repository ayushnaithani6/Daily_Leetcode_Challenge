class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        
        string longestPrefix = strs[0];
        
        for(int i=1; i<strs.size(); ++i) {
            
            if(longestPrefix == "") {
                break;
            }
            
            int minLen = min(longestPrefix.size(), strs[i].size());
            string common = "";
            
            for(int j=0; j<minLen; ++j) {
                if(longestPrefix[j] == strs[i][j]) {
                    common += longestPrefix[j];
                }
                else {
                    break;
                }
            }
            
            if(common.size() < longestPrefix.size()) {
                longestPrefix = common;
            }
        }
        
        return longestPrefix;
    }
};
