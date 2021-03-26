class Solution {
public:
    vector<string> generateParenthesis(int n) {
//         base case
//         string size == 2*n
//         stop condition invalid parenthesis or more ( or ) than n
//         analyze first
        vector<string> allCombinations;
        generateParenthesisUtil(n, allCombinations);
        return allCombinations;
    }
    
    
    void generateParenthesisUtil(int n, vector<string> &allCombinations, string s = "", int k=0) {
        if(k == 2*n) {
            // push to vector string
            allCombinations.push_back(s);
            return;
        }
        
        string newOpen = s+'(';
        if(checkValidity(newOpen, n)) {
            generateParenthesisUtil(n, allCombinations, newOpen, k+1);
        }
        string newClose = s+')';
        if(checkValidity(newClose, n)) {
            generateParenthesisUtil(n, allCombinations, newClose, k+1);
        }
    }
    
    bool checkValidity(string s, int n) {
        int openBracket = 0;
        int closeBracket = 0;
        for(int i=0; i<s.size(); ++i) {
            if(s[i] == '(') {
                ++openBracket;
            }
            else {
                ++closeBracket;
            }
            
            if(closeBracket > openBracket || openBracket > n || closeBracket > n) {
                return false;
            }
        }
        return true;
    }
};
