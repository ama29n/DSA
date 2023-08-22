#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    bool check(vector<int> &piles, int h, int k) {
        ll count = 0;
        for(auto it : piles) {
            count += it / k;
            if((it % k) != 0) count++;
        }
        if(count <= h)
            return true;
        return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int beg = 1, end = INT_MIN, k = 0;
        for(auto it : piles) {
            end = max(end, it);
        }
        while(beg <= end) {
            int mid = beg + (end - beg) / 2;
            if(check(piles, h, mid)) {
                k = mid;
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        return k;
    }
};
