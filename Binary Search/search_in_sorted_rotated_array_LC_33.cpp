#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target) {

    int l = 0, r = nums.size() - 1;

    while (l <= r){

        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;

        if (nums[mid] <= nums[r]) { // here we are using = for the cases where nums[mid] == nums[r] - [4,5,6,7,0,1,2], find - 3
            if (target >= nums[mid] && target <= nums[r]) l = mid + 1; 
            else r = mid - 1;
        }

        else if (nums[mid] >= nums[l]) { // [3,1], find - 0
            if (target <= nums[mid] && target >= nums[l]) r = mid - 1;
            else l = mid + 1;
        }
    }
    return -1;
}