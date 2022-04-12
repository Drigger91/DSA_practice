#include<bits/stdc++.h>
// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

// Implement the MyQueue class:

// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Notes:

// You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.



class MyQueue {
public:
    stack<int> st, q_stack;
    int count;
    MyQueue() {
        st = stack<int>();
        q_stack = stack<int>();
        count = 0;
    }
    void push(int x){
        count++;
        if (st.empty() && q_stack.empty()){
             q_stack.push(x);   
        }
        else if (st.empty()){
            while(!q_stack.empty()){
                st.push(q_stack.top());
                q_stack.pop();
            }
            st.push(x);
            while(!st.empty()){
                q_stack.push(st.top());
                st.pop();
            }
        }
    }
    int pop(){
        if(count){
            count--;
            int toReturn = q_stack.top();
            q_stack.pop();
            return toReturn;
        }
        return 0;
        
    }
    
    int peek() {
       if (count){
           return q_stack.top();
       }
        return 0;
    }
    
    bool empty(){
        if (count){ 
            return false;
        }
        return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */