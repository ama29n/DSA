#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    unordered_set<int> s;

    // Adds a new element to the set.
    s.insert(2);

    // Removes the value ‘g’ from the set.
    s.erase(2);

    // Removes all the elements from the set.
    s.clear();

    // Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.
    s.find(2);

    // Returns an iterator to the first element in the set.
    s.begin();

    // Returns an iterator to the theoretical element that follows the last element in the set.
    s.end();

    // Returns the number of elements in the set.
    s.size();

    // Returns whether the set is empty.
    s.empty();

    // Returns the maximum number of elements that the set can hold.
    s.max_size();

    // Returns 1 or 0 based on the element ‘g’ is present in the set or not.
    s.count(2);
}

//                 |     set             | unordered_set
// ---------------------------------------------------------
// Ordering        | increasing  order   | no ordering
//                 | (by default)        |

// Implementation  | Self balancing BST  | Hash Table  

// search time     | log(n)              | O(1) -> Average 
//                 |                     | O(n) -> Worst Case

// Insertion time  | log(n) + Rebalance  | Same as search
                      
// Deletion time   | log(n) + Rebalance  | Same as search