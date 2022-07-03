#include <bits/stdc++.h>
using namespace std;

// A dynamic array is quite similar to a regular array, but its size is modifiable during program runtime. 
// DynamArray elements occupy a contiguous block of memory.

// Once an array has been created, its size cannot be changed. However, a dynamic array is different. 
// A dynamic array can expand its size even after it has been filled.

// During the creation of an array, it is allocated a predetermined amount of memory. 
// This is not the case with a dynamic array as it grows its memory size by a certain factor when there is a need.

int main() {
    int n;
    cout << "Enter the number of items:" << "\n";
	cin >> n;
	int *arr = new int(n);
	cout << "Enter " << n << " items" << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\nElements are\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    delete [] arr;
    return;
}

int main() {
    int x; 

	int *array{ new int[5]{ 10, 7, 15, 3, 11 } };

	cout << "Array elements: " << endl;

	for (x = 0; x < 5; x++) {
		cout << array[x] << endl;
	}

    delete [] array;
}


// 2D array 
int main() {
    // Declaration
    int row, col;
    int** matrix = new int*[col];
    for(int i = 0; i < col; i++)
        matrix[i] = new int[row];

    
    // Deletion
    for(int i = 0; i < col; ++i) {
        delete [] matrix[i];
    }
    delete [] matrix;
}


// The length of a dynamic array is set during the allocation time.

// However, C++ doesn’t have a built-in mechanism of resizing an array once it has been allocated.

// You can, however, overcome this challenge by allocating a new array dynamically, copying over the elements, 
// then erasing the old array.

// Note: that this technique is prone to errors, hence, try to avoid it.





// A dynamic array should be deleted from the computer memory once its purpose is fulfilled. 
// The delete statement can help you accomplish this. 

// The released memory space can then be used to hold another set of data. 

// However, even if you do not delete the dynamic array from the computer memory, 
// it will be deleted automatically once the program terminates.

// To delete a dynamic array from the computer memory, you should use delete[], instead of delete. 
// The [] instructs the CPU to delete multiple variables rather than one variable. 
// The use of delete instead of delete[] when dealing with a dynamic array may result in problems. 
// Examples of such problems include memory leaks, data corruption, crashes, etc.



// Memset

int main () {
    int a[5];
  
    // all elements of A are zero
    memset(a, 0, sizeof(a));
}