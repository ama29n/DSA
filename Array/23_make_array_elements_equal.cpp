#include <bits/stdc++.h>
using namespace std;

// We are given an array, we need to find the minimum number of increment and decrement operations (by 1) required 
// to make all the array elements equal.

// We need to make the elements of this array equal arr[] = {2, 4, 5, 7, 10}.

// x[0] => 5 - 2 = 3 (3 increments)
// x[1] => 5 - 4 = 1 (1 increment)
// x[2] => 5 - 5 = 0
// x[3] => 7 - 5 = 2 (2 decrements)
// x[4] => 10 - 5 = 5 (5 decrements)
// Minimum number of operations = 3 + 1 + 2 + 5 = 11 with 4 increments and 7 decrements.
// These operations will result in arr[] = {5, 5, 5, 5, 5}


// Approach 1 
// Brute force - O(n ^ 2)
// Try to make all array same for every element and track the minimum element 



// Approach 2 
// For calculating minimum number of operations to equalize an array, we need to make sure that all the elements 
// are incremented to a value, so that they become equal in the least number of increment/decrement operations.
// For this, we should select a number which is, basically, nearest to all the elements in the array.

// This element will be the middle element of a sorted array.All the elements to the left of this element, 
// will be incremented to its value and all the elements to its right will be decremented to its value.

int cal(vector<int>& nums) {
    int n = nums.size();
    int m1 = nums[n / 2];
    int m2 = nums[n / 2 - 1];
    int s1 = 0, s2 = 0;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++) {
        s1 += abs(m1 - nums[i]);
        s2 += abs(m2 - nums[i]);
    }
    
    return min(s1, s2);
}