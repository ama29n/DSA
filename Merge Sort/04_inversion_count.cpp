#include <bits/stdc++.h >
using namespace std;

// https://www.codingninjas.com/codestudio/problems/count-inversions_615 

// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1 

// Brute Force - O(n ^ 2)
class Solution{
  public:
    long long int inversionCount(long long arr[], long long N) {
        long long ans = 0;
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(arr[i] > arr[j]) {
                    ans++;
                }
            }
        }
        return ans;
    }

};

// Merge Sort
typedef long long ll;
vector<ll> nums;
void merge(ll l, ll m, ll r) {
    ll n = r - l + 1;
    vector<ll> v(n);
    ll i = l, j = m + 1, k = 0;
    while(k < n) {
        ll x = i <= m ? nums[i] : INT_MAX;
        ll y = j <= r ? nums[j] : INT_MAX;
        v[k++] = x <= y ? nums[i++] : nums[j++]; 
    }
    for(ll idx = 0; idx < n; idx++) {
        nums[l + idx] = v[idx];
    }
}
ll mergeSort(ll l, ll r) {
    if(l >= r) {
        return 0;
    }
    int m = l + (r - l) / 2;
    ll ans = mergeSort(l, m) + mergeSort(m + 1, r);
    int i = l, j = m + 1;
    while(i <= m && j <= r) {
        if(nums[i] > nums[j]) {         // 5 6 7 8       1 2 9 10
            ans += (m - i + 1);
            j++;
        } else {
            i++;
        }
    }
    merge(l, m, r);
    return ans;
}
long long getInversions(long long *arr, int N){
    nums.resize(N);
    for(ll i = 0; i < N; i++) {
        nums[i] = arr[i];
    }
    return mergeSort(0, N - 1);
}