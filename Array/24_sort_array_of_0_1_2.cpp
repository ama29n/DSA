#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& a) {
    int red = 0, white = 0, blue = a.size() - 1;
    while(white <= blue) {
        switch(a[white]) {
            // If the element is 0
        case 0:
            swap(a[red++], a[white++]);
            break;

        // If the element is 1 .
        case 1:
            white++;
            break;

        // If the element is 2
        case 2:
            swap(a[white], a[blue--]);
            break;
        }
    }
}