#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/substring-xor-queries/

typedef long long ll;
typedef pair<int, int> p;

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        unordered_map<ll, p> map;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                if(map.find(0) == map.end())
                    map[0] = {i, i};
                continue;
            }
            ll sum = 0;
            for(int j = i; j < i + 32 && j < n; j++) {
                sum = (sum << 1) + (s[j] - '0');
                if(map.find(sum) == map.end()) {
                    map[sum] = {i, j};
                }
            }
        }
        for(auto it : queries) {
            ll x = it[0] ^ it[1];
            if(map.find(x) != map.end()) {
                ans.push_back({map[x].first, map[x].second});
            } else {
                ans.push_back({-1, -1});
            }
        }
        return ans;
    }
};