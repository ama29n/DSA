#include <bits/stdc++.h>
using namespace std;

// Merge Sort

// Average, Worst & Best TC -> O(n log(n))
// Space -> O(n)

// In Merge Sort, the given unsorted array with n elements, is divided into n subarrays, each having one element, 
// because a single element is always sorted in itself. Then, it repeatedly merges these subarrays, 
// to produce new sorted subarrays, and in the end, one complete sorted array is produced.

// The concept of Divide and Conquer involves three steps:
// Divide: the problem into multiple small problems.
// Conquer: the subproblems by solving them. The idea is to break down the problem into atomic subproblems, where they are actually solved.
// Combine: the solutions of the subproblems to find the solution of the actual problem.

// Algorithm 
// We take "l" as the starting index of the array and "r" as the end index of the array.
// Then we find the middle of the array as "m = (l + r) / 2", and divide the array into 2 subarrays from "l" to "m" and "m + 1" to "r".
// Then we keep on dividing these subarrays into furthur subarrays until we are left with 1 element.
// Then we start merging these subarrays in sorted manner.

void merge(vector<int>& v, int l, int m, int r) {
    int size = r - l + 1;
    vector<int> nums(size);
    int i = l, j = m + 1, k = 0;
    while(k < size) {
        int x = i > m ? INT_MAX : v[i];
        int y = j > r ? INT_MAX : v[j];
        nums[k++] = x <= y ? v[i++] : v[j++];
    }
    for(int i = 0; i < size; i++) {
        v[l + i] = nums[i];
    }
}

void mergeSort(vector<int>& v, int l, int r) {
    if(l >= r) {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(v, l, m);        // T(n / 2)
    mergeSort(v, m + 1, r);    // T(n / 2) 
    merge(v, l, m, r);         // n
}

/*.....................................................................*/

int main() {
    // Size of array
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    mergeSort(v, 0, n - 1);
}