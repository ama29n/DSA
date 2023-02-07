#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int l, int m, int r) {
    int size = r - l + 1;
    int nums[size];
    int i = l, j = m + 1, k = 0;
    while(k < size) {
        int x = i > m ? INT_MAX : arr[i];
        int y = j > r ? INT_MAX : arr[j];
        nums[k++] = x <= y ? arr[i++] : arr[j++];
    }
    for(int idx = 0; idx < size; idx++) {
        arr[idx + l] = nums[idx];
    }
}

void sort(int arr[], int l, int r) {
    if(l >= r) {
        return;
    }
    int m = (l + r) / 2;
    sort(arr, l, m);
    sort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    int arr[5] = {5, 4, 3, 2, 1};
    print(arr, 5);
    sort(arr, 0, 4);
    print(arr, 5);
}
