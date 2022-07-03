#include <bits/stdc++.h>
using namespace std;

// In C++ STL, by default, the top element is always the greatest element.
// We can also change it to the smallest element at the top. 
// Priority queues are built on the top to the max heap and uses array or vector as an internal structure.

int main() {
    // Priority queue of max-heap
    priority_queue<int> q;

    // Insert element in queue
    q.push(1);

    // Returns top element in the queue
    q.top();

    // Delete top element in queue
    q.pop();

    // Returns the size of queue
    q.size();

    // Returns whether the queue is empty
    q.empty();


    // Priority queue of min-heap
    priority_queue <int, vector<int>, greater<int>> q;
}

typedef pair<int, int> p;

int main() {
    // Priority queue of type pair and max-heap, the elements will be sorted on the basis of 1st element of the pair
    priority_queue<p> q;

    // Priority queue of type pair and min-heap
    priority_queue <p, vector<p>, greater<p>> q;
}