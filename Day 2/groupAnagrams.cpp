class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         more efficient approach
        unordered_map<string, vector<string>> anagrams;
        
        vector<string> sortedStrs = strs;
        for(int i=0; i<strs.size(); ++i) {
            sort(sortedStrs[i].begin(), sortedStrs[i].end());
        }
        
        for(int i=0; i<strs.size(); ++i) {
            if(anagrams.find(sortedStrs[i]) != anagrams.end()) {
                anagrams[sortedStrs[i]].push_back(strs[i]);
            }
            else {
                anagrams[sortedStrs[i]] = {};
                anagrams[sortedStrs[i]].push_back(strs[i]);
            }
        }
        
        vector<vector<string>> group;
        for(auto it: anagrams) {
            group.push_back(it.second);
        }
        
        return group;
    }
};
