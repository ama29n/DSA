#include <bits/stdc++.h>
using namespace std;

// The size of the pointers in C is equal for every pointer type. 
// The size of the pointer does not depend on the type it is pointing to. 
// It only depends on the operating system and CPU architecture. 

// When a variable is declared as a reference, it becomes an alternative name for an existing variable. 
// Reference variables can only be initialized unlike pointers which can be initialised as well as assigned.

int main() {
    int a = 10;
    int *ptr;
    ptr = &a;
    int &b = a;
    // But we cannot change the reference
    int c = 7;
    ptr = &c; // This is valid
    &b = c; // This is not valid
}

// Types
int main() {
    // Integer Pointer - Even the array name is the pointer to its first element. 
    int *ptr;


    // Array Pointer
    char *ptr = &array_name;


    // Structure Pointer
    struct struct_name *ptr;


    // Double Pointer or pointer-to-pointer - A pointer that stores the memory address of another pointer.
    datatype ** pointer_name;

    // Dereferencing
    *pointer_name; // get the address stored in the inner level pointer
    **pointer_name; // get the value pointed by inner level pointer


    // NULL Pointer
    data_type *pointer_name = NULL;


    // Void Pointer 
    void *ptr;


    // Wild Pointers - Which have not been initialised yet
    int *ptr;
    char *chtr;


    // Constant Pointer
    // The memory address stored inside the pointer is constant and cannot be modified once it is defined.
    // It will always point to the same memory address.
    data_type * const pointer_name;


    // Pointer to Constant
    // The pointers pointing to a constant value that cannot be modified are called pointers to a constant. 
    // Here we can only access the data pointed by the pointer, but cannot modify it. 
    // Although, we can change the address stored in the pointer to constant.
    const data_type * pointer_name;


    // Dangling Pointer - A pointer pointing to a memory location that has been deleted is called a dangling pointer.
}

// void pointers can not be dereferenced
int main() {
    int a = 10, b = 9;
    void *ptr;
    ptr = &a;
    ptr = &b;
    cout << ptr << " " << *ptr;
}

// Example of Double Pointer
int main() {
    int a = 10;
    int *ptr = &a;
    int **temp = &ptr;
    cout << temp;     // 0x8
    cout << *temp;    // 0x4
    cout << ptr;      // 0x4
    cout << **temp;   // 10
}

// Constant Pointer
int main() {
    int a = 10;
    int * const ptr = &a;
    int b = 7;
    ptr = &b; // error: assignment of read-only variable ‘ptr’
}

// Pointer to Constant
int main() {
    int a = 10;
    const int *ptr;
    ptr = &a;
    *ptr = 300;  // assignment of read-only location ‘* ptr’
    (*ptr)++;    // This is valid
    int b = 7;   // error: increment of read-only location ‘* ptr’
    ptr = &b;    // This is valid
}

// Pointer Arithmatic

// 1. Increment in a Pointer
// 2. Decrement in a Pointer
// 3. Addition of integer to a pointer
// 4. Subtraction of integer to a pointer
// 5. Subtracting two pointers of the same type
// 6. Comparison of pointers of the same type
// 7. Assignment of pointers of the same type

// Incrementing Pointer
int main() {
    int a = 10;
    int *ptr;
    ptr = &a;
    cout << ptr;    // 0x3c
    ptr++;
    cout << ptr     // 0x40
    cout << *ptr;   // Garbage Value
}

// Addition of an Integer
int main() {
    int a = 10;
    int *ptr;
    ptr = &a;
    cout << ptr; // 0x1c
    ptr += 2;
    cout << ptr; // 0x24 (+8)
}

// Assignment and Comparison
int main() {
    int a = 10;
    int *ptr1 = &a;
    int b = 10;
    int *ptr2 = &b;
    ptr1 = ptr2;
    if(ptr1 == ptr2) {
        cout << "Assignment and Comparison";
    }
}

// Incrementing Value
int main() {
    int a = 10;
    int *ptr = &a;
    ++*ptr;
    cout << *ptr;  // 11
    cout << a;     // 11
}

// Program to show Pointer Arithmatic
int main() {
    int v[3] = { 10, 100, 200 };
    int* ptr;
    ptr = v;
    for (int i = 0; i < 3; i++) {
        // print value at address which is stored in ptr
        cout << *ptr << " " << ptr << endl;
        ptr++;
    }
    return 0;
}
// 0x10 10
// 0x14 100
// 0x18 200

// Program to access array elements using pointer
int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };
    int* ptr_arr = &arr;
    for (int i = 0; i < 5; i++) {
        cout << *ptr_arr++;
    }
    return 0;
}
// 1 2 3 4 5

// https://www.geeksforgeeks.org/pointer-array-array-pointer/


// Swap by Value vs Swap by Pointer
// Need 
// 1. To modify local variables
// 2. If size of arguments is large, it is then more efficient
class Swap {
    public:

    // The value of the arguments is accessed via the dereferencing operator (*)
    // Pointers can contain a NULL value, so a passed argument may point to a NULL or even a garbage value. 
    void swapByPointer(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    // References cannot contain a NULL value, so it is guaranteed to have some value. 
    void swapByReference(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int main() {
        int a = 10, b = 20;
        swapByPointer(&a, &b); // 20 10
        swapByReference(a, b); // 10 20 (Again swapped)
    }
};


// Predict Output
int main() {
    int num[5];
    int* p;
    p = num;
    *p = 10;
    p++;
    *p = 20;
    p = &num[2];
    *p = 30;
    p = num + 3;
    *p = 40;
    p = num;
    *(p + 4) = 50;
    for (int i = 0; i < 5; i++) {
        cout << num[i] << " ";
    }
}
// 10 20 30 40 50


// Predict Output
int main() {
    int x[5] = { 1, 2, 3, 4, 5 };
    // p points to array x
    int* p = x;
    int i;
    // exchange values using pointer
    for (i = 0; i < 2; i++) {
        int temp = *(p + i);
        *(p + i) = *(p + 4 - i);
        *(p + 4 - i) = temp;
    }
    // output the array x
    for (i = 0; i < 5; i++) {
        cout << x[i] << " ";
    }
    return 0;
}
// 5 4 3 2 1

// Pointer to Array 
// We can declare a pointer that can point to whole array instead of only one element of the array. 

int main() {
    data_type (*var_name)[size_of_array];
    int (*ptr)[10]; 
}

// Example
int main() {
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};

    int *p = arr;             // Pointer to 1st element of array
    int (*ptr)[n];            // Pointer to whole array
    ptr = &arr;

    cout << "p = " << p << ", ptr = " << ptr;      // p = 0x30, ptr = 0x30
    
    // Increment both pointers 
    p++; ptr++;

    cout << "p = " << p << ", ptr = " << ptr;      // p = 0x34, ptr = 0x44
}


// Array of pointers
int main() {
    int *var_name[array_size];
     int *ptr[3];
}


int main() {
     int *ptr_arr[3] = {new int(1), new int(2), new int(3)};
     for(int i = 0; i < 3; i++) {
        cout << *ptr_arr[i] << " ";
     }
}
// 1 2 3