#include <iostream>
using namespace std;

int main() {
    int n = 4;
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; i++, j++) {
            cout << i << " " << j << endl;
        }
    }
}

// 00 01 02 03
// 10 11 12 13
// 20 21 22 23
// 30 31 32 33

// 0 0
// 1 1
// 2 2
// 3 3
// 0 1
// 1 2
// 2 3
// 0 2
// 1 3
// 0 3