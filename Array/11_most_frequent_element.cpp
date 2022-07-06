#include <bits/stdc++.h>
using namespace std;

// Return the most repeated element... If 2 elements have same frequency return the smallest of them

// Brute force
// Time - O(n ^ 2) 
int maxRepeating(int *arr, int n, int k) {
    int ele, fre = 0;
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j])
                count++;
        }
        if(count > fre) {
            fre = count;
            ele = arr[i];
        }
        if(count == fre) {
            ele = min(ele, arr[i]);
        }
    }
    return ele;
}


// Using map
// Time - O(n)
// Space - O(n)
int maxRepeating(int *arr, int n, int k) {
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
        mp[arr[i]]++;
    
    int ele, fre = 0;
    for(auto it : mp) {
        if(it.second > fre) {
            fre = it.second;
            ele = it.first;
        }
        else
        if(it.second == fre) {
            ele = min(ele, it.first);
        }
    }
    return ele;
}


// Using sorting 
// Time - O(n logn)
int maxRepeating(vector<int>& nums, int n, int k) {
    sort(nums.begin(), nums.end());
    
    int fre = 1, maxFre = 0, ele;

    // For all the same elements we increase the count and when the element changes, we check if it is the most frequent
    for(int i = 1; i < n; i++) {
        // We will only consider the case when the frequency is larger than the previous greater frequency
        // The case with equal frequency doesn't needs to be included because the array is sorted 
        // The previous element with the same frequency as the current one is smaller 
        if(nums[i] != nums[i - 1]) {
            if(fre > maxFre) {
                maxFre = fre;
                ele = nums[i - 1];
            }
            fre = 1;
        } else {
            fre++;
        }
    }
    // If last element has the maximum frequency
    if(fre > maxFre)
        ele = nums[n - 1];
    return ele;
}