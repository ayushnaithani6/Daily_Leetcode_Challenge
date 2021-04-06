// any path rate maze 4  dirction travel
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &v, vector<vector<int>> &result, int r, int c) {
    if(r >= 0 && r < v.size() && c >= 0 && c < v.size() && v[r][c] == 1 && result[r][c] == 0) {
        return true;
    }
    return false;
}

bool possiblePathMazeUtil(vector<vector<int>> &v, vector<vector<int>> &result, int r, int c) {

    if(r == v.size()-1 && c == v.size()-1) {
        result[r][c] = 1;
        return true;
    }

    // is current position safe
    if(isSafe(v, result, r, c)) {
        result[r][c] = 1;

        if(possiblePathMazeUtil(v, result, r+1, c)) {
            return true;
        }

        if(possiblePathMazeUtil(v, result, r, c+1)) {
            return true;
        }
        
        if(possiblePathMazeUtil(v, result, r, c-1)) {
            return true;
        }
        
        if(possiblePathMazeUtil(v, result, r-1, c)) {
            return true;
        }

        result[r][c] = 0;
    }
    return false;
}

vector<vector<int>> possiblePathMaze(vector<vector<int>> &v) {
    vector<vector<int>> result(v.size(), vector<int>(v.size(), 0));
    int r=0, c=0;
    possiblePathMazeUtil(v, result, r, c);
    return result;
}


int main() {
    vector<vector<int>> v = {{1, 0, 0, 0}, {1, 1, 1, 0}, {1, 1, 1, 1}, {0, 1, 0, 1}};
    vector<vector<int>> result = possiblePathMaze(v);
    int n = 4;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}