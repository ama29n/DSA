#include<bits/stdc++.h>
using namespace std;

int main () {
    int arr[100];
    cout << (&arr)[1] - arr;
    return 0;
}


// Find if a number is even or odd
// For odd numbers, (n&1) is equal to 1
// For even numbers, (n&1) is equal to 0

// if(n&1){
// //…Odd
// }else{
// //Even…
// }