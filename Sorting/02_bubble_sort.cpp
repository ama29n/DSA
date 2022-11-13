#include <bits/stdc++.h>
using namespace std;

// Bubble Sort

// Bubble sort works on the repeatedly swapping of adjacent elements until they are not in the intended order. 
// It is called bubble sort because the movement of array elements is just like the movement of air bubbles in the water. 
// Bubbles in water rise up to the surface; similarly, the array elements in bubble sort move to the end in each iteration.

void sort_1(vector<int>& v, int n) {
    // Algorithm
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
    // This algorithm always runs O(n ^ 2) times even if the array is sorted.
    // It can be optimized by stopping the algorithm if the inner loop didn’t cause any swap. 
}

void sort_2(vector<int>& v, int n) {
    // Optimised Algorithm
    bool swapped;
    for(int i = 0; i < n - 1; i++) {
        swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false) {
            break;
        }
    }
    // Average & Worst TC -> O(n ^ 2)
    // Best TC -> O(n)
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
    sort_2(v, n);
}