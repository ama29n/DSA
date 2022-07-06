#include <bits/stdc++.h>
using namespace std;

// The peak element in an array is an array element which is not smaller than it's neighbours. 
// For example, given an array of {6,7,10,12,9} 12 is the peak element of the array. 
// Another example is an array of {8,15,9,2,23,5} in this case, there are two peak elements:15 and 23.

// However, there are some edge cases to be considered.

// 1. One edge case can be when all elements in the array are the same such as {5,5,5}. The peak element is 5.
// 2. The second edge case to consider is when the elements in the array are sorted in descending order 
//    i.e from the highest to the lowest.{50,40,30,20}.50 is the peak element.
// 3. The final edge is elements in an array sorted in ascending order i.e the lowest element to the 
//    highest element {20,30,40,50,70,90}. The peak element is 90.


// Approach 1
// O(n)
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)
        return 0;
    // If array is sorted in ascending order
    if(nums[n - 1] > nums[n - 2])
        return n - 1;
    // If array is sorted in descending order
    if(nums[0] > nums[1])
        return 0;
    int ele;
    for(int i = 1; i < n - 1; i++)
        if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            ele = i;
            break;
        }
    return ele;
}




// Approach 2 
// Binary Search logn 
// if the element on the right side of the middle element is greater than the middle element, 
// iterate to the right of the array for the peak element.Hence, beg = mid + 1
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int beg = 0, end = n - 1;
    
    while(beg <= end) {
        int mid = beg + (end - beg) / 2;

        // Wrap around conditions 
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if(nums[mid] > nums[next] && nums[mid] > nums[prev])
            return mid;

        // [1,2,1,3,5,6,4]   [1,2,3,4,5]   [4,3,2,1,2,3]
        if(nums[next] > nums[mid])
            beg = mid + 1;
        else 
            end = mid - 1;
    }
    return 0;
}






// Peak Index in Mountain Array

// Let's call an array arr a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
//      arr[0] < arr[1] < ... arr[i-1] < arr[i]
//      arr[i] > arr[i+1] > ... > arr[arr.length - 1]

int peakIndexInMountainArray(vector<int>& nums) {
    int n = nums.size();
    int beg = 0, end = n - 1;
    while(beg <= end) {
        int mid = beg + (end - beg) / 2;
        int next = (mid + 1);
        int prev = (mid - 1);
        if(nums[mid] > nums[next] && nums[mid] > nums[prev])
            return mid;
        if(nums[next] > nums[mid])
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}