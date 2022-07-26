#include <bits/stdc++.h>
using namespace std;


// O(n ^ 3)
void subarrays(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            for(int k = i; k <= j; k++) {
                cout << nums[k] << " ";
            }
            cout << endl;
        }
    }
}

// n = 5

// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5 
// 2 
// 2 3 
// 2 3 4 
// 2 3 4 5 
// 3 
// 3 4 
// 3 4 5 
// 4 
// 4 5 
// 5 


