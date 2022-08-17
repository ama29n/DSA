#include <iostream>
using namespace std;

bool check(int pages, int m, int nums[], int n) {
    int parts = 1;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(count + nums[i] > pages) {
            parts++;
            count = nums[i];
            if(count > pages)
            return false;
        } else {
            count += nums[i];
        }
    }
    if(parts <= m) 
    return true;
    return false;
}
//Function to find minimum number of pages.
int findPages(int nums[], int n, int m) {
    int beg = INT_MAX, end = 0;
    for(int i = 0; i < n; i++) {
        beg = min(beg, nums[i]);
        end += nums[i];
    }
    int maxiPages = 0;
    while(beg <= end) {
        int mid = beg + (end - beg) / 2;
        if(check(mid, m, nums, n)) {
            end = mid - 1;
            // cout << mid << " ";
            maxiPages = mid;
        } else {
            beg = mid + 1;
        }
    }
    return maxiPages;
}