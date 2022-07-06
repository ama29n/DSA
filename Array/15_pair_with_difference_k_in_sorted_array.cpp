#include <bits/stdc++.h>
using namespace std;

// Brute force - O(n ^ 2)

// Approach 2 
// Using binary search
// O(n logn)
// For every element we will find if another element in the array exists such that k + that element equals the later element 

// To further optimise it, we can save the elements in map or set and eliminate log n port