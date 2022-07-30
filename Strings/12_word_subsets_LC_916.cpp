#include <bits/stdc++.h>
using namespace std;

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<int> mp1(26, 0);
    for(auto s : words2) {
        vector<int> m(26, 0);
        for(auto it : s)
            m[it - 'a']++;
        for(int i = 0; i < 26; i++)
            mp1[i] = max(mp1[i], m[i]);
    }
    vector<string> ans;
    for(auto s : words1) {
        vector<int> mp2(26, 0);
        for(auto it : s)
            mp2[it - 'a']++;
        int flag = 1;
        for(int i = 0; i < 26; i++) {
            if(mp1[i] != 0 && mp2[i] < mp1[i])
                flag = 0;
        }
        if(flag)
            ans.push_back(s);
    }
    return ans;
}