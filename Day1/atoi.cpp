class Solution {
public:
    int myAtoi(string s) {
        stringstream t(s);
        int x=0;
        t >>x;

        return x;
    }
};
