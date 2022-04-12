#include<bits/stdc++.h>
// Design a stack which supports the following operations.

// Implement the CustomStack class:

// CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack or do nothing if the stack reached the maxSize.
// void push(int x) Adds x to the top of the stack if the stack hasn't reached the maxSize.
// int pop() Pops and returns the top of stack or -1 if the stack is empty.
// void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, just increment all the elements in the stack.

class CustomStack {
    private:
    stack<int>s1;
    stack<int>s2;
    int size = 0;
public:
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(s1.size()<size){
            s1.push(x);
        }
    }
    
    int pop() {
        if(s1.empty()){
            return -1;
        }
        else{
            int top = s1.top();
            s1.pop();
            return top;
        }
    }
    
    void increment(int k, int val) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        while(!s2.empty()){
            if(k>0){
                s1.push(s2.top()+val);
                k--;
                s2.pop();
            }
            else{
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
};