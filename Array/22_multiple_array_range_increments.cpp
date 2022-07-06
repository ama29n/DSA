#include <bits/stdc++.h>
using namespace std;

// Given an array A containing N integers, we perform M queries. Each query has three values START, END and a value D. 
// For each query, the problem is to increment the values from the start to end index(both inclusive) in the given array 
// by the given value d. 
// A naive solution of leaping from start to end for each query is not feasible which takes O(N M) time 
// whereas the efficient algorithm takes O(N + M) time complexity.

// Efficient Approach

// 1. We create an array of the same size n and initialize all its elements to 0.
// 2. Then, for each query i, we increment element at index start by d and decrement element at index end by d.
// 3. After all the queries are completed, we loop from 1 to n-1 in temp and increment each element by the element 
//    at its previous index.
// 4. Finally, we loop from 0 to n-1 and increment each element of a by its corresponding value in temp.
// 5. The required array after modification is obtained.

// Time - O(M + N)