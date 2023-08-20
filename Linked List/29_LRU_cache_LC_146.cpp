#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lru-cache/ 

class LRUCache {
private:
    // Class Node 
    class Node {
    public:
        int key, value;
        Node *next, *prev;
        Node(int _key, int _value) {
            key = _key; value = _value;
            next = prev = NULL;
        }
    };
    // Data Members
    unordered_map<int, Node *> map;
    int capacity;
    Node *list_front, *list_end;
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        // Make "front" and "end" node of the list
        list_front = new Node(-1, -1);
        list_end = new Node(-1, -1);
        list_front->next = list_end;
        list_end->prev = list_front;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()) {
            // "node" corresponding to key
            Node *node = map[key];

            // Remove node from it's current position
            node->prev->next = node->next;
            node->next->prev = node->prev;

            // Make "next" & "prev" of node NULL
            node->next = NULL; node->prev = NULL;

            // Insert node at the start

            // Connect right side pointers
            node->next = list_front->next;
            node->next->prev = node; // or list_front->next->prev
            // Connect left side pointers
            list_front->next = node;
            node->prev = list_front;

            // Return "value"
            return node->value;
        }

        // If "node" is not present in the map
        return -1;
    }
    
    void put(int key, int _value) {
        // If "key" is already present, update the position in list & the "value"
        if(map.find(key) != map.end()) {
            // "node" corresponding to key
            Node *node = map[key];

            // Remove node from it's current position
            node->prev->next = node->next;
            node->next->prev = node->prev;

            // Make "next" & "prev" of node NULL
            node->next = NULL; node->prev = NULL;

            // Insert node at the start
            
            // Connect right side pointers
            node->next = list_front->next;
            node->next->prev = node;
            // Connect left side pointers
            list_front->next = node;
            node->prev = list_front;

            // Update Value
            node->value = _value;

            return;
        } 

        // "key" is not present

        // if capacity is reached, remove the last node
        if(map.size() == capacity) {
            // "last node"
            Node *node = list_end->prev;

            node->prev->next = list_end; // list_end or node->next;
            list_end->prev = node->prev; // list_end or node->next;

            // Remove "last node" from map
            map.erase(node->key);

            // Delete the node
            delete node;
        }

        // Create new node
        Node *node = new Node(key, _value);

        // Add new node at the beginning of the list
        // Connect right side pointers
        node->next = list_front->next;
        list_front->next->prev = node;
        // Connect left side pointers
        list_front->next = node;
        node->prev = list_front;

        // Add node to map
        map[key] = node;
    }
};