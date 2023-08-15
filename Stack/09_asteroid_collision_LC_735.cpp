#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        for(auto it : asteroids) {
            // It only makes sense to check the asteroids going in left direction
            if(!s.empty() && it < 0) {
                // While the asteroids prior to current one are moving to right and are smaller, they will be destroyed
                while(!s.empty() && s.top() > 0 && abs(it) > s.top()) {
                    s.pop();
                }
                // If an asteroid is moving to right and is equal in size, both will be destroyed 
                // and this can be executed only once
                if(!s.empty() && s.top() > 0 && abs(it) == s.top()) {
                    s.pop(); 
                    continue;
                }
                // If the current asteriod destroyed all others or if there is no asteroid moving to right 
				// which is greater in magnitude than the current one 
                if(s.empty() || s.top() < 0) {
                    s.push(it);
                }
            } else {
                s.push(it);
            }
        }
        vector<int> ans;
        while(!s.empty()) { ans.push_back(s.top()); s.pop(); }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};