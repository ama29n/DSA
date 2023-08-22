#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r) {
    int n = r - l + 1;
    vector<int> v(n);
    int i = l, j = m + 1, k = 0;
    while(k < n) {
        int x = i <= m ? arr[i] : INT_MAX;
        int y = j <= r ? arr[j] : INT_MAX;
        v[k++] = x < y ? arr[i++] : arr[j++]; 
    }
    for(int i = 0; i < n; i++) {
        arr[l + i] = v[i];
    }
}
void mergeSort(vector<int> &arr, int l, int r) {
    if(l >= r) {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr{3, 6, 1, 2, 5, 4};
    mergeSort(arr, 0, arr.size() - 1);
    for(auto it : arr) {
        cout << it << " ";
    }
}