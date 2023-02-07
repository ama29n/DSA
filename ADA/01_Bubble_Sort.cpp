#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int arr[], int n) {
    bool swapped;
    for(int i = 0; i < n - 1; i++) {
        swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false) {
            break;
        }
    }
}

int main() {
    int arr[5] = {5, 4, 3, 2, 1};
    print(arr, 5);
    sort(arr, 5);
    print(arr, 5);
}
