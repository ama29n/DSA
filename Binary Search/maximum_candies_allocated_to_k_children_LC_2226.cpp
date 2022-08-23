#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    
    bool canSplit(ll size, vector<int>& candies, long long k) {
        ll count = 0;
        for(auto it : candies)
            count += (it / size);
        if(count >= k)
            return true;
        return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        ll beg = 1, end = LLONG_MIN, maxCandies = 0;
        for(auto it : candies)
            if(it > end)
                end = it;
        while(beg <= end) {
            ll mid = beg + (end - beg) / 2;
            if(canSplit(mid, candies, k)) {
                beg = mid + 1;
                maxCandies = mid;
            } else {
                end = mid - 1;
            }
        }
        return maxCandies;
    }
};