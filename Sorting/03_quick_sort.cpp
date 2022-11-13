#include <bits/stdc++.h>
using namespace std;

// Quick Sort 

// It is a Divide and Conquer Algorithm.

// The concept of Divide and Conquer involves three steps:
// Divide: In Divide, first pick a pivot element. After that, partition or rearrange the array into two sub-arrays such that each element 
// in the left sub-array is less than or equal to the pivot element and each element in the right sub-array is larger than the pivot element.
// Conquer: Recursively, sort two subarrays with Quicksort.
// Combine: Combine the already sorted array.

int partition(vector<int>& v, int l, int r) {
    int pivot = l, i = l, j = r;
    while(i <= j) {
        while(i <= r && v[i] <= v[pivot])
            i++;
        while(j > l && v[j] > v[pivot])
            j--;
        if(i < j) {
            swap(v[i], v[j]);
        }
    }
    swap(v[pivot], v[j]);
    return j;
}

void quickSort(vector<int>& v, int l, int r) {
    if(l >= r)
        return;
    int p = partition(v, l, r);    // n
    quickSort(v, l, p - 1);        // T(n / 2)
    quickSort(v, p + 1, r);        // T(n / 2) 
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
    quickSort(v, 0, n - 1);
}

