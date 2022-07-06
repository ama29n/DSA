#include <bits/stdc++.h>
using namespace std;

// Intution 
// Bianry search is applied when we know the range 
// We can find the element, by deciding a range and then search the element in the array by dividing it into pieces of size range
// However if the range is constant and the size of the array is very large, the time also tends towards constant 
// Thus, we make the range the exponential

int bs(int *arr, int beg, int end, int ele) {
    int l = beg, r = end;
    while(l <= r) {
        int mid = beg + (end - beg) / 2;

        if(arr[mid] == ele)
            return mid;

        if(arr[mid] > ele)
            r = mid - 1;
        else 
            l = mid + 1;
    }
    return 0;
}

int binarySearch(int *arr, int ele) {
    int beg = 0, end = 1;
    while(arr[end] < ele) {
        beg = end;
        end *= 2;
    }
    return bs(arr, beg, end, ele);
}