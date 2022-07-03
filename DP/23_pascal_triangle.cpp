#include <bits/stdc++.h>
using namespace std;

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