#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/count-number-subarrays-given-xor/

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

// An Efficient Solution solves the above problem in O(n) time. 
// Let us call the XOR of all elements in the range [i+1, j] as A, in the range [0, i] as B, 
// and in the range [0, j] as C. If we do XOR of B with C, the overlapping elements in [0, i] from B and C 
// zero out, and we get XOR of all elements in the range [i+1, j], i.e. A. Since A = B XOR C, we have B = A XOR C. 
// Now, if we know the value of C and we take the value of A as m, we get the count of A as the count of all B 
// satisfying this relation. Essentially, we get the count of all subarrays having XOR-sum m for each C. 
// As we take the sum of this count overall C, we get our answer.

long long subarrayXor(int arr[], int n, int m) {
    long long ans = 0; // Initialize answer to be returned
 
    // Create a prefix xor-sum array such that
    // xorArr[i] has value equal to XOR
    // of all elements in arr[0 ..... i]
    int* xorArr = new int[n];
 
    // Create map that stores number of prefix array
    // elements corresponding to a XOR value
    unordered_map<int, int> mp;
 
    // Initialize first element of prefix array
    xorArr[0] = arr[0];
 
    // Computing the prefix array.
    for (int i = 1; i < n; i++)
        xorArr[i] = xorArr[i - 1] ^ arr[i];
 
    // Calculate the answer
    for (int i = 0; i < n; i++) {
       
        // Find XOR of current prefix with m.
        int tmp = m ^ xorArr[i];
 
        // If above XOR exists in map, then there
        // is another previous prefix with same
        // XOR, i.e., there is a subarray ending
        // at i with XOR equal to m.
        ans = ans + ((long long)mp[tmp]);
 
        // If this subarray has XOR equal to m itself.
        if (xorArr[i] == m)
            ans++;
 
        // Add the XOR of this subarray to the map
        mp[xorArr[i]]++;
    }
 
    // Return total count of subarrays having XOR of
    // elements as given value m
    return ans;
}