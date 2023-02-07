#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int pivotElement(int arr[], int l, int r) {
    int pivot = l, i = l, j = r;
    while(i <= j) {
        while(i <= r && arr[i] <= arr[pivot]) {
            i++;
        }
        while(j > l && arr[j] > arr[pivot]) {
            j--;
        }
        if(i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[pivot], arr[j]);
    return j;
}

void sort(int arr[], int l, int r) {
    if(l >= r) {
        return;
    }
    int p = pivotElement(arr, l, r);
    sort(arr, l, p - 1);
    sort(arr, p + 1, r);
}

int main() {
    int arr[5] = {5, 4, 3, 2, 1};
    print(arr, 5);
    sort(arr, 0, 4);
    print(arr, 5);
}
