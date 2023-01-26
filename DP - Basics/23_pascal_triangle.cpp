#include <bits/stdc++.h>
using namespace std;



//  1
//  1  1
//  1  2  1
//  1  3  3  1
//  1  4  6  4  1

// numRows = 5
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++) {
            row[j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
        ans.push_back(row);
    }
    return ans;
}







double factorial(int n) {
    double p = 1;
    for(double i = 1; i <= n; i++)
        p = p * i;
    return p;
}

vector<vector<int>> generate(int n) {
    vector<vector<int>> answer;
    vector<double> dp(30, -1);
    
    for(int i = 0; i < n; i++) {
        vector<int> row;
        for(int j = 0; j <= i; j++) {
            double a, b, c;
            
            if(dp[i] != -1) a = dp[i];
            else a = dp[i] = factorial(i);
            
            if(dp[j] != -1) b = dp[j];
            else b = dp[j] = factorial(j);
            
            if(dp[i - j] != -1) c = dp[i - j];
            else c = dp[i - j] = factorial(i - j);
                
            double com = a / (b * c);
            cout << com << " ";
            row.push_back((int)com);
        }
        answer.push_back(row);
        cout << endl;
    }
    return answer;
}

int main() {
    vector<vector<int>> a = generate(25);
}
