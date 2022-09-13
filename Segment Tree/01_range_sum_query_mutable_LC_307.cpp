#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    int arr[100005], seg[4 * 100005], n;
    
    void buildTree(int i, int low, int high) {
        if(low == high) {
            seg[i] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        buildTree(2 * i + 1, low, mid);
        buildTree(2 * i + 2, mid + 1, high);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    
    int findSum(int i, int low, int high, int l, int r) {
        if(low >= l && high <= r)
            return seg[i];
        if(high < l || low > r)
            return 0;
        int mid = (low + high) / 2;
        int left = findSum(2 * i + 1, low, mid, l, r);
        int right = findSum(2 * i + 2, mid + 1, high, l, r);
        return left + right;
    }
    
    void updateTree(int i, int index, int val, int low, int high) {
        if(high == low) {
            seg[i] = val;
            return;
        }
        int mid = (low + high) / 2;
        if(low <= index && index <= mid) {
            updateTree(2 * i + 1, index, val, low, mid);
        } else {
            updateTree(2 * i + 2, index, val, mid + 1, high);
        }
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    
    NumArray(vector<int>& nums) {
        this -> n = nums.size();
        for(int i = 0; i < n; i++)
            arr[i] = nums[i];
        buildTree(0, 0, n - 1);
    }
    
    void update(int index, int val) {
        updateTree(0, index, val, 0, n - 1);
    }
    
    int sumRange(int left, int right) {
        int ans = findSum(0, 0, n - 1, left, right);
        return ans;
    }
};