#include <bits/stdc++.h>
using namespace std;

// For arrays
class Solution {   
    // n = 6
    // 0 1 2 3 4 5
    // l = 0, r = 5, mid = 2
    public:
    void merge(int arr[], int l, int mid, int r) {
         int n1 = mid - l + 1;
         int n2 = r - mid;
         int subarr1[n1], subarr2[n2];
         for(int i = 0; i < n1; i++)
            subarr1[i] = arr[l + i];
         for(int i = 0; i < n2; i++)
            subarr2[i] = arr[mid + 1 + i];
         int i = 0, j = 0, k = l;
         while(i < n1 && j < n2) {
             if(subarr1[i] <= subarr2[j]) {
                 arr[k] = subarr1[i];
                 i++, k++;
             } else {
                 arr[k] = subarr2[j];
                 j++, k++;
             }
         }
         while(i < n1) {
             arr[k] = subarr1[i];
             i++, k++;
         } 
         while(j < n2) {
             arr[k] = subarr2[j];
             j++, k++;
         }
    }
    void mergeSort(int arr[], int l, int r) {
        if(l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};

// For vector 
void merge(vector<int>& arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
        int n2 = r - mid;
        vector<int> subarr1, subarr2;
        for(int i = 0; i < n1; i++)
            subarr1.push_back(arr[l + i]);
        for(int i = 0; i < n2; i++)
            subarr2.push_back(arr[mid + 1 + i]);
        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2) {
            if(subarr1[i] <= subarr2[j])
                arr[k++] = subarr1[i++];
            else
                arr[k++] = subarr2[j++];
        }
        while(i < n1)
            arr[k++] = subarr1[i++];
        while(j < n2)
            arr[k++] = subarr2[j++];
}
void mergeSort(vector<int>& arr, int l, int r) {
    if(l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}