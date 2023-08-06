#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/count-number-subarrays-given-xor/

// https://www.codingninjas.com/studio/problems/count-subarrays-with-given-xor_1115652 

// O(n ^ 2)
long long subarrayXor(int arr[], int n, int m) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int xorSum = 0;
        for (int j = i; j < n; j++) {
            xorSum = xorSum ^ arr[j];
            if (xorSum == m)
                ans++;
        }
    }
    return ans;
}

// Time - O(n) and Space - O(n)

int subarraysXor(vector<int> &arr, int x) {
    int n = arr.size();

    // Create a prefix xor-sum array such that
    // xorArr[i] has value equal to XOR
    // of all elements in arr[0 ..... i]
    vector<int> preXor(n);

    // Computing the prefix array
    preXor[0] = arr[0];
    for(int i = 1; i < n; i++) {
        preXor[i] = preXor[i - 1] ^ arr[i];
    }

    // Calculate the answer
    unordered_map<int, int> map;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        // Find XOR of current prefix with m
        int temp = x ^ preXor[i];

         // If above XOR exists in map, then there
        // is another previous prefix with same
        // XOR, i.e., there is a subarray ending
        // at i with XOR equal to m
        ans += map[temp];

        // If this subarray has XOR equal to m itself
        // This is not inlcuded in map yet
        if(preXor[i] == x) {
            ans++;
        }

        // Add the XOR of this subarray to the map
        map[preXor[i]]++;
    }
    return ans;
}