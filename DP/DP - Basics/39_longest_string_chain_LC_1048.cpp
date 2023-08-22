#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-string-chain/ 

bool comparator(string a, string b) {
    return a.size() < b.size() ? true : false;
}

class Solution {
public:
    bool compare(string a, string b) {
        int m = a.size(), n = b.size();
        if(n > m || m != n + 1)
            return false;
        int i, j, onePass = 1;
        for(i = 0, j = 0; i < m ; ) {
            if(a[i] != b[j] && onePass) {
                onePass = 0;
                i++;
            } 
            else if(a[i] != b[j])
                return false;
            else i++, j++;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comparator);
        int n = words.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            int maxi = 1;
            for(int j = 0; j < i; j++) {
                if(compare(words[i], words[j]))
                    if(dp[i] + dp[j] > maxi)
                        maxi = dp[i] + dp[j];
            }
            dp[i] = maxi;
        }
        int ans;
        for(auto it : dp)
            ans = max(ans, it);
        return ans;
    }
};