#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/beautiful-towers-ii/

class Solution {
private:
    int n;
    vector<int> nextSmaller(vector<int> &nums) {
        vector<int> next(n, n);
        stack<int> s;
        s.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return next;
    }

    vector<int> prevSmaller(vector<int> &nums) {
        vector<int> prev(n, -1);
        stack<int> s;
        s.push(0);
        for (int i = 1; i < n; i++) {
            while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return prev;
    }

public:
    long long maximumSumOfHeights(vector<int> &maxi) {
        n = maxi.size();
        vector<int> next = nextSmaller(maxi);
        vector<int> prev = prevSmaller(maxi);
        vector<long long> l(n, 0), r(n, 0);

        // Calculate l[i] for each tower
        for (int i = 0; i < n; i++) {
            if (prev[i] != -1) {
                l[i] += l[prev[i]] + (i - prev[i]) * (long long)maxi[i];
            } else {
                l[i] += (i - prev[i]) * (long long)maxi[i];
            }
        }

        // Calculate r[i] for each tower
        for (int i = n - 1; i >= 0; i--) {
            if (next[i] != n) {
                r[i] += r[next[i]] + (next[i] - i) * (long long)maxi[i];
            } else {
                r[i] += (next[i] - i) * (long long)maxi[i];
            }
        }

        long long ans = 0;

        // Calculate the maximum possible sum of heights for a beautiful configuration
        for (int i = 0; i < n; i++) {
            ans = max(ans, l[i] + r[i] - maxi[i]);
        }

        return ans;
    }
};
