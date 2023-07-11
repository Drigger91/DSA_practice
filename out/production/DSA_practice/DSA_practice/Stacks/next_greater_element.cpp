#include<bits/stdc++.h>
// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.


 vector<int> nextGreaterElements(vector<int>& nums) {
        //brute force tle;
        // vector<int> ans;
        // for(int i=0;i<nums.size();i++){
        //     if(checkFront(nums,i)!=INT_MIN){
        //         ans.push_back(checkFront(nums,i));
        //     }
        //     else if(checkBack(nums,i)!=INT_MIN){
        //         ans.push_back(checkBack(nums,i));
        //     }
        //     else{
        //         ans.push_back(-1);
        //     }
        // }
        // return ans;
        
        //stack approach
        stack<int> s;
        for(int i=nums.size()-1;i>=0;i--){
            s.push(nums[i]);
        }
        vector<int> ans(nums.size(),-1);
        for(int i=nums.size()-1;i>=0;i--){
            int curr= nums[i];
            while(!s.empty() and s.top()<=curr){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
                
            }
            else{
                ans[i]=s.top();
            }
            s.push(curr);
        }
        return ans;
    }