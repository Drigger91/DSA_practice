// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
 

// Example 1:

// Input: s = "()"
// Output: true

//solution
#include<stack>
#include<bits/stdc++.h>


bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('|| s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if(s[i]=='}'){
                    if(st.top()=='{'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(s[i]==')'){
                    if(st.top()=='('){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(s[i]==']'){
                    if(st.top()=='['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }