#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-performance-of-a-team/ 

// Time Complexity: O(N * (log N + log K)) 
// Space Complexity: O(N + K)
// where N is the total number of candidates and K is the size of team

class Solution {
private:
    #define ll long long int
    int MOD = 1E9 + 7;
public:
    int maxPerformance(int n, vector<int> &Speed, vector<int> &Efficiency, int k) {
        vector<pair<int, int>> engineer(n);
        for(int i = 0; i < n; i++) {
            engineer[i] = { Efficiency[i], Speed[i] };
        }
        sort(engineer.rbegin(), engineer.rend());
        // PQ of min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        ll speed_sum = 0;
        ll ans = 0;
        for(auto &it : engineer) {
            int efficiency = it.first, speed = it.second;
            speed_sum += speed;
            pq.push(speed);
            // Remove the engineer with lowest speed 
            // If the current engineer has the lowest speed then, 
            // ans will be uneffected as the sum will remain same and efficiency is moving in decreasing order 
            if(pq.size() > k) {
                speed_sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, (speed_sum * efficiency));
        }
        return ans % MOD;
    }
};
