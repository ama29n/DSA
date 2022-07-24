#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string s, int k) {
    if(k > s.size())
        return false;
    vector<int> map(26, 0);
    for(auto it : s) 
        map[it - 'a']++;
    int oddChars = 0;
    for(int i = 0; i < 26; i++) {
        if((map[i] & 1))
            oddChars++;
        
    }
    return oddChars <= k ? true : false;
}