#include <bits/stdc++.h>
using namespace std;

class Inefficient {
private:
    stack<int> main_stack, mini_stack;
public:
    MinStack() {
        // Use 2 stacks
    }
    void push(int val) {
        main_stack.push(val);
        if(mini_stack.empty() || val <= mini_stack.top())
            mini_stack.push(val);
    }
    void pop() {
        int temp = main_stack.top();
        main_stack.pop();
        if(mini_stack.top() == temp)
            mini_stack.pop();
    }
    int top() {
        return main_stack.top();
    }
    int getMin() {
        return  mini_stack.top();
    }
};


// With Constant Space 
class MinStack {
private:
    stack<int> s;
    int min_ele;
public:   
    MinStack() {
        min_ele = 0;
    }
    void push(int val) {
        if(s.empty()) {
            s.push(val);  min_ele = val;  return;
        }
        if(val >= min_ele) {
            s.push(val);  return;
        }
        s.push((2 * val) - min_ele);
        min_ele = val;
    } 
    void pop() {
        if(s.top() >= min_ele) {
            s.pop();  return;
        }
        min_ele = (2 * min_ele) - s.top();
        s.pop();
    }
    int top() {
        return s.top();
    }
    int getMin() {
        return min_ele;
    }
};
