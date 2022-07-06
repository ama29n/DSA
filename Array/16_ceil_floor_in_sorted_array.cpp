#include <bits/stdc++.h>
using namespace std;

int findFloor(long long int arr[], int n, long long int x) {
    if(x < arr[0])
        return -1;
    int beg = 0, end = n - 1;
    while(beg <= end) {
        int mid = beg + (end - beg) / 2;
        if(arr[mid] == x)
            return mid;
        if(arr[mid] > x)
            end = mid - 1;
        else beg = mid + 1;
    }
    return end;
}
