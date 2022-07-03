#include<bits/stdc++.h>
using namespace std;

int cal(int idx, vector<int> &energy) {
    if(idx == 0)
    return 0;
    if(idx == 1)
    return abs(energy[1] - energy[0]);
    int oneStepBack = cal(idx - 1, energy) + abs(energy[idx] - energy[idx - 1]);
    int twoStepBack = cal(idx - 2, energy) + abs(energy[idx] - energy[idx - 2]);
    return min(oneStepBack, twoStepBack);
}

int main() {
    int n = 6;
    vector<int> energy(n), dp(n);
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        energy[i] = data;
    }

    int ans = cal(n - 1, energy);
    cout << ans;
}


// Memoization 

// int cal(int idx, vector<int> &height, vector<int> &dp) {
//     if(idx == 0)
//         return 0;
//     if(idx == 1)
//         return abs(height[1] - height[0]);
//     if(dp[idx] != -1)
//         return dp[idx];
    
//     dp[idx - 1] = cal(idx - 1, height, dp);
//     dp[idx - 2] = cal(idx - 2, height, dp);
    
//     return min(dp[idx - 1] + abs(height[idx] - height[idx - 1]), dp[idx - 2] + abs(height[idx] - height[idx - 2]));
// }

// int frogJump(int n, vector<int> &heights) {
// 	vector<int> dp(n, -1);
//     return cal(n - 1, heights, dp);
// }







// Tabulation

// int frogJump(int n, vector<int> &height) {
// 	vector<int> dp(n, -1);
//     dp[0] = 0;
//     dp[1] = abs(height[1] - height[0]);
    
//     for(int i = 2; i < n; i++) {
//         int one = dp[i - 1] + abs(height[i] - height[i - 1]);
//         int two = dp[i - 2] + abs(height[i] - height[i - 2]);
//         dp[i] = min(one, two);
//     }
//     return dp[n - 1];
// }




// Super optimised


// int frogJump(int n, vector<int> &height) {
//     int twoPrev = 0, onePrev = abs(height[1] - height[0]), cur;
    
//     for(int i = 2; i < n; i++) {
//         int one = onePrev + abs(height[i] - height[i - 1]);
//         int two = twoPrev + abs(height[i] - height[i - 2]);
//         cur = min(one, two);
     
//         twoPrev = onePrev;
//         onePrev = cur;
//     }
//     return cur;
// }