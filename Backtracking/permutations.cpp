#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> answer;
    
    void per(vector<int> &arr, int l, int r) {
        if(l == r) {
            answer.push_back(arr);
            return;
        }
        
        for(int i = l; i < r; i++) {
            swap(arr[i], arr[l]);
            per(arr, l + 1 ,r);
            swap(arr[i], arr[l]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        per(nums, 0, nums.size());
        return answer;
    }
};

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]