// ALGO EXPERT UNDERSCORIFY STRING
#include <bits/stdc++.h>
using namespace std;

void findIntervals(vector<pair<int, int>> &intervals, string &text, string &pattern) {
    int n = pattern.size();
    for(int i=0; i<text.size(); ++i) {
        size_t pos = text.find(pattern, i);
        if(pos == string::npos) {
            return;
        } else {
            intervals.push_back({pos, pos+n});
            i = pos;
        }
    }
}

void collapseInterval(vector<pair<int, int>> &c_intervals, vector<pair<int, int>> intervals) {
    if(c_intervals.size() == 0) {
        c_intervals.push_back(intervals[0]);
    }
    int p = 0;
    for(int i=1; i<intervals.size(); ++i) {
        pair<int, int> interval = intervals[i];
        if(c_intervals[p].second >= interval.first) {
            // merge those
            c_intervals[p].second = interval.second;
        } else {
            // push interval to c_intervals and inc p
            c_intervals.push_back(interval);
            ++p;
        }
    }
}

int main() {
    string text, pattern;
    getline(cin, text);
    cin >> pattern;

    // find Interval function
    vector<pair<int, int>> intervals;
    findIntervals(intervals, text, pattern);
    if(intervals.size() == 0) {
        cout << "No such pattern exists in text";
        return 0;
    }
    
    // collapse Interval function
    vector<pair<int, int>> c_intervals;
    collapseInterval(c_intervals, intervals);


    // underscorify string
    string newText = "";
    int p = 0;
    pair<int, int> curInterval = c_intervals[p];
    for(int i=0; i<text.size(); ++i) {
        if(i == curInterval.first) {
            newText.push_back('_');
        } else if(i == curInterval.second) {
            newText.push_back('_');
            curInterval = c_intervals[++p];
        } 
        newText.push_back(text[i]);
    }
    cout << newText;
}






// input : "testthis is a testtest to see if testestest it works", "test"
// output : "_test_this is a _testtest_ to see if _testestest_ it works"
