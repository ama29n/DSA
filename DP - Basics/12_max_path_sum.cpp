#include<bits/stdc++.h>
using namespace std;

// variable starting point and variable end point


int path(int rows, int ele, vector<vector<int>> &matrix) {
    if(rows == matrix.size() - 1) {
        return matrix[rows][ele];
    }
    
    int down = path(rows + 1, ele, matrix);
    int diaLeft = -100000;
    int diaRight = -100000;
    if(ele + 1 < matrix[0].size() - 1) diaRight = path(rows + 1, ele + 1, matrix);
    if(ele - 1 >= 0) diaLeft = path(rows + 1, ele - 1, matrix);
    
    return max(down, max(diaLeft, diaRight)) + matrix[rows][ele];
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    int rows = matrix.size(), maxPath = -100000;
    for(int i = 0; i < matrix[0].size(); i++) {
        maxPath = max(maxPath, path(0, i, matrix));
    }
    return maxPath;
}

int main() {

    int r = 3, c = 3;
    vector<vector<int>> matrix(r, vector<int> (c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int it;
            cin >> it;
            matrix[i][j] = it;
        }
    }

    int ans = getMaxPathSum(matrix);
    cout << ans;
}





// Memoization

int path(int rows, int ele, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if(rows == matrix.size() - 1) {
        return matrix[rows][ele];
    }
    if(dp[rows][ele] != -1)
        return dp[rows][ele];
    
    int down = path(rows + 1, ele, matrix, dp);
    int diaLeft = INT_MIN;
    int diaRight = INT_MIN;
    if(ele + 1 < matrix[0].size()) diaRight = path(rows + 1, ele + 1, matrix, dp);
    if(ele - 1 >= 0) diaLeft = path(rows + 1, ele - 1, matrix, dp);
    
    return dp[rows][ele] = max(down, max(diaLeft, diaRight)) + matrix[rows][ele];
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    int rows = matrix.size(), col = matrix[0].size(), maxPath = INT_MIN;
    vector<vector<int>> dp(rows, vector<int> (col, -1));
    for(int i = 0; i < matrix[0].size(); i++) {
        maxPath = max(maxPath, path(0, i, matrix, dp));
    }
    return maxPath;
}

