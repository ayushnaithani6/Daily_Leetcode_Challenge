// n queen problem
// find all possible combinations
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nQueen(int);
void nQueenUtil(int, int, vector<vector<int>>&, vector<int>&);
bool isSafe(vector<int> &);

int main() {
    vector<vector<int>> result = nQueen(8);

    for(int i=0; i<result.size(); ++i) {
        for(int j=0; j<4; ++j) {
            // printing on basis of index starting from 1
            cout << result[i][j]+1 << " ";
        }
        cout << endl;
    }     
    return 0;
}

// returning all possible combination of cols (remember all backtracking)
vector<vector<int>> nQueen(int n) {
    vector<vector<int>> result;
    vector<int> colPlacements;
    int row = 0;
    nQueenUtil(n, row, result, colPlacements);
    return result;
}

void nQueenUtil(int n, int row, vector<vector<int>> &result, vector<int> &colPlacements) {
    // base condition
    if(row == n) {
        result.push_back(colPlacements);
        return;
    }

    for(int col=0; col<n; ++col) {
        colPlacements.push_back(col);
        if(isSafe(colPlacements)) {
            nQueenUtil(n, row+1, result, colPlacements);
        }
        colPlacements.pop_back();
    }
}

bool isSafe(vector<int> &colPlacements) {
    int rowId = colPlacements.size()-1;

    for(int i=0; i<rowId; ++i) {
        // dif between columns
        int dif = abs(colPlacements[i] - colPlacements[rowId]);
                             //difference between row
        if(dif == 0 || dif == rowId-i) {
            return false;
        }
    }
    return true;
}