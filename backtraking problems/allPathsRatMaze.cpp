
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &v, vector<vector<int>> &result, int r, int c) {
    if(r >= 0 && r < v.size() && c >= 0 && c < v.size() && v[r][c] == 1 && result[r][c] == 0) {
        return true;
    }
    return false;
}

void allPathMazeUtil(vector<vector<int>> &v, vector<vector<int>> &result, int r, int c) {

    if(r == v.size()-1 && c == v.size()-1) {
        result[r][c] = 1;
        for(int i=0; i<v.size(); ++i) {
            for(int j=0; j<v.size(); ++j) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        result[r][c] = 0;
        return;
    }
    
    if(isSafe(v, result, r, c)) {
        result[r][c] = 1;
        allPathMazeUtil(v, result, r+1, c);
        allPathMazeUtil(v, result, r-1, c);
        allPathMazeUtil(v, result, r, c+1);
        allPathMazeUtil(v, result, r, c-1);
        result[r][c] = 0;  
    }
}


void allPathMaze(vector<vector<int>> &v) { 
    vector<vector<int>> result(v.size(), vector<int>(v.size(), 0));
    int r=0, c=0;
    allPathMazeUtil(v, result, r, c);
    cout << endl;
    cout << "final result matrix all index should be zero" << endl;
    int n = 3;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> v = {{1, 0, 1}, {1, 1, 1}, {1, 1, 1}};
    allPathMaze(v);
    return 0;
}