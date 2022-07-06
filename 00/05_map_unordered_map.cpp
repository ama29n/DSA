#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> hashmap;
    unordered_map<int, int> hashmap;

    // Adds a new key value pair to the map.
    hashmap.insert({2, 3});

    // Removes the key value pair of the mentioned key from the map.
    hashmap.erase(2);

    // Removes all the elements from the map.
    hashmap.clear();

    // Returns an iterator to the element ‘g’ in the map if found, else returns the iterator to end.
    hashmap.find(2);

    // Returns an iterator to the first element in the map.
    hashmap.begin();

    // Returns an iterator to the theoretical element that follows the last element in the map.
    hashmap.end();

    // Returns the number of elements in the map.
    hashmap.size();

    // Returns whether the map is empty.
    hashmap.empty();

    // Returns the maximum number of elements that the map can hold.
    hashmap.max_size();

    // Returns 1 or 0 based on the element with the entered key is present in the map or not.
    hashmap.count(2);
}

//                 |     map             | unordered_map
// ---------------------------------------------------------
// Ordering        | increasing  order   | no ordering
//                 | (by default)        |

// Implementation  | Self balancing BST  | Hash Table  

// search time     | log(n)              | O(1) -> Average 
//                 |                     | O(n) -> Worst Case

// Insertion time  | log(n) + Rebalance  | Same as search
                      
// Deletion time   | log(n) + Rebalance  | Same as search