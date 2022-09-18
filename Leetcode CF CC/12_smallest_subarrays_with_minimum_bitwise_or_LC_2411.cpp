#include <bits/stdc++.h>
using namespace std;

// You are given a 0-indexed array nums of length n, consisting of non-negative integers. For each index i from 0 to n - 1, 
// you must determine the size of the minimum sized non-empty subarray of nums starting at i (inclusive) that has the maximum 
// possible bitwise OR.

// Input: nums = [1,0,2,1,3]
// Output: [3,3,2,2,1]
// Explanation:
// The maximum possible bitwise OR starting at any index is 3. 
// - Starting at index 0, the shortest subarray that yields it is [1,0,2].
// - Starting at index 1, the shortest subarray that yields the maximum bitwise OR is [0,2,1].
// - Starting at index 2, the shortest subarray that yields the maximum bitwise OR is [2,1].
// - Starting at index 3, the shortest subarray that yields the maximum bitwise OR is [1,3].
// - Starting at index 4, the shortest subarray that yields the maximum bitwise OR is [3].
// Therefore, we return [3,3,2,2,1]. 

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> last(30, 0), res(n, 1);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < 30; j++) {
                if(nums[i] & (1 << j))
                    last[j] = i;
                res[i] = max(res[i], last[j] - i + 1);
            }
        }
        return res;
    }
};