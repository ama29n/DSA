#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int *arr, int l, int r, int ele) {
        while(l <= r) {
            int mid = beg + (end - beg) / 2;
            if(arr[mid] == ele)
                return mid;
            if(arr[mid] > ele) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return 0;
    }
    int binarySearch(int *arr, int ele) {
        int beg = 0, end = 1;
        while(arr[end] < ele) {
            beg = end;
            end *= 2;
        }
        return find(arr, beg, end, ele);
    }
};