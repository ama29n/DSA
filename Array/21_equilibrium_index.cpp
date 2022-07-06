#include <bits/stdc++.h>
using namespace std;

// For a given array, we need to find an index such that sum of left sub-array = right sub-array also called the Equilibrium Index.
// Equilibrium index is the index of the element in the array such that the sum of all the elements left to the index 
// is equal to the sum of all the elements right to the index.

// Approach 1 
// Brute force - O(n ^ 2)

// Approach 2 
// Suffix and prefix arrays
int equilibriumPoint(long long a[], int n) {
    if(n == 1)
        return 1;
    if (n == 2)
        return -1;
    int l[n], r[n];
    l[0] = a[0];
    for(int i = 1; i < n; i++) {
        l[i] = a[i] + l[i - 1];
    }
    r[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        r[i] = a[i] + r[i + 1];
    }
    for(int i = 1; i < n - 1; i++)
        if(l[i - 1] == r[i + 1])
            return i + 1;
    return -1;
}