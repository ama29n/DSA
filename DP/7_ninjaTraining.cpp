#include<bits/stdc++.h>
using namespace std;


// Recursive Solution 

// int ninja(int day, vector<vector<int>> &points, int last) {
//     if(day == 0) {
//         int maxi = 0;
//         for(int i = 0; i < 3; i++) 
//             if(last != i) 
//                 maxi = max(points[day][i], maxi);
//         return maxi;
//     }
    
//     int maxi = 0;
//     for(int i = 0; i < 3; i++) {
//         if(last != i)
//             maxi = max(maxi, points[day][i] + ninja(day - 1, points, i));
//     }
//     return maxi;
// }

// int ninjaTraining(int n, vector<vector<int>> &points) {
//     int ans = ninja(n - 1, points, 3);
//     return ans;
// }





// Memoization

// int ninja(int day, vector<vector<int>> &points, int last, vector<vector<int>> &dp) {
//     if(day == 0) {
//         int maxi = 0;
//         for(int i = 0; i < 3; i++) 
//             if(last != i) 
//                 maxi = max(points[day][i], maxi);
//         return maxi;
//     }
    
//     if(dp[day][last] != -1) return dp[day][last];
    
//     int maxi = 0;
//     for(int i = 0; i < 3; i++) {
//         if(last != i) {
//             maxi = max(maxi, points[day][i] + ninja(day - 1, points, i, dp));
//         }
//     }
//     return dp[day][last] = maxi;
// }

// int ninjaTraining(int n, vector<vector<int>> &points) {
//     vector<vector<int>> dp(n, vector<int> (4, -1));
//     int ans = ninja(n - 1, points, 3, dp);
//     return ans;
// }

// here, dp[] stores the best combination available for dp[day][last] i.e. when which last is occupied for current day










// Tabulation

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int> (4, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 4; last++) {
			dp[day][last] = 0;

            for(int i = 0; i < 3; i++) {
                if(i != last) {
                    int point = points[day][i] + dp[day - 1][i];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}