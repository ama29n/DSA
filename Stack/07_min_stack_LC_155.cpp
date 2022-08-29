#include <bits/stdc++.h>
using namespace std;

// With Extra Space 
// Use 2 stacks
class MinStack {
public:
    stack<int> s, ss;
    
    MinStack() {
        // ss -> supporting stack
        // This Stack stores the minimum element up until current point
    }

    // <= condition 
    // ["MinStack","push","push","push","getMin","pop","getMin"]
    // [[],[0],[1],[0],[],[],[]]
    
    void push(int val) {
        s.push(val);
        if(ss.empty() || val <= ss.top())
            ss.push(val);
    }
    
    void pop() {
        int popEle = s.top();
        s.pop();
        if(ss.top() == popEle)
            ss.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ss.top();
    }
};


// With Constant Space 
class MinStack {
public:
    stack<int> s;
    int minEle;
    
    MinStack() {
        minEle = 0;
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push(val);
            minEle = val;
            return;
        }
        if(val >= minEle) {
            s.push(val);
            return;
        }
        s.push((2 * val) - minEle);
        minEle = val;
    }
    
    void pop() {
        if(s.top() >= minEle) {
            s.pop();
            return;
        }
        minEle = (2 * minEle) - s.top();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minEle;
    }
};
