// this solution is not optimal one .... 
// revisit this problem

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_memo;
        for(int i=0; i<t.size(); ++i) {
            t_memo[t[i]] += 1;
        }
        
        int l=0, r=0;
        vector<int> minWinIdx = {-1, -1};
        
        unordered_map<char, int> s_memo;
        s_memo[s[r]] = 1;
        while(l < s.size() && r < s.size()) {
            
            if(checkKeys(t_memo, s_memo)) {
                
                if(minWinIdx[0] == -1 || minWinIdx[1]-minWinIdx[0]+1 > r-l+1) {
                    minWinIdx[0] = l;
                    minWinIdx[1] = r;
                    // cout << l << " " << r;
                }
                
                --s_memo[s[l]];
                ++l;
            }
            
            else {
                ++r;
                ++s_memo[s[r]];
            }
        }
        
        
        if(minWinIdx[0] == -1) return "";
        return s.substr(minWinIdx[0], minWinIdx[1]-minWinIdx[0]+1);
    }
    
    bool checkKeys(unordered_map<char, int> &t_memo, unordered_map<char, int> &s_memo) {
        for(auto p: t_memo) {
            if(s_memo[p.first] < t_memo[p.first]) {
                return false;
            }
        }
        return true;
    }
};
