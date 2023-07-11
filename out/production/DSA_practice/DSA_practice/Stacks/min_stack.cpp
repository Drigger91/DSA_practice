#include<bits/stdc++.h>
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.

class MinStack {
    private:
    stack<int>s1;
    stack<int>s2;
public:
    void push(int val) {
        s1.push(val);
        if(s2.empty() or val<=s2.top()){
            s2.push(val);
        }
    }
    
    void pop() {
        //first check
        if(s1.top()==s2.top()){
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};