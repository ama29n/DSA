#include <bits/stdc++.h>
using namespace std;

// Cycle Sort

// Advantages ->        1. No extra memory is required. 2. In place sorting algorithm.
// Dis-advantages ->    1. Unstable. 2. Time Complexity of O(n ^ 2)

// Cycle Sort for general case
// Worst, Best & Average TC -> O(n ^ 2)
int cycleSort(vector<int>& v, int n) {
    int swaps = 0;
    int cycle_start = 0;
    while(cycle_start <= n - 2) {
        int cur_ele = v[cycle_start];
        int pos = cycle_start;
        for(int i = cycle_start + 1; i < n; i++) {
            if(v[i] < cur_ele)
                pos++;
        }
        if(pos == cycle_start) {
            cycle_start++;
            continue;
        }
        // Ignore duplicate elements
        while(cur_ele == v[pos])
            pos++;
        swap(v[cycle_start], v[pos]);
        swaps++;
    }
    return swaps;
}

// This algorithm is only used when the elements are in the range [1, n], n = size of the array
// Worst, Average & Best TC - O(n)
void cycleSort_1(vector<int>& v, int n) {
    int i = 0;
    while(i < n) {
        int correct_idx = v[i] - 1;
        if(i != correct_idx) {
            swap(v[i], v[correct_idx]);
        } else {
            i++;
        }
    }
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
    cycleSort_1(v, n);
}

// Questions to practice 

// https://leetcode.com/problems/missing-number/
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/