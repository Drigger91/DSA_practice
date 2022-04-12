#include<bits/stdc++.h>
//1. Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.


vector<int>nextSmallElement(vector<int>arr){
        stack<int>s;
        s.push(-1);
        vector<int>ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(s.top()!=-1 and arr[s.top()]>=arr[i]){            //because we want index that's why arr[s.top()]
                s.pop();
            } 
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>prevSmallElement(vector<int>arr){
        stack<int>s;
        s.push(-1);
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(s.top()!=-1 and arr[s.top()]>=arr[i]){            //because we want index that's why arr[s.top()]
                s.pop();
            } 
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        //brute force tle
//         int max_area = 0;
//         for(int i=0;i<heights.size();i++){
//             int area = heights[i];
//             int j = i-1;
//             int count=0;
//             while(j>=0 and heights[j]>=area){
//                 count++;
//                 j--;
//             }
//             j=i+1;
//             while(j<heights.size() and heights[j]>=area){
//                 count++;
//                 j++;
//             }
//             area = area+area*count;
//             max_area = max(max_area,area);
            
//         }
//         return max_area;
        //approach-2 using stack
        
        int n = heights.size();
        vector<int>next(n);
        vector<int>prev(n);
        next = nextSmallElement(heights);
        prev = prevSmallElement(heights);
        int max_area = 0;
        for(int i=0;i<n;i++){
            if(next[i]==-1){
                next[i]=n;
            }
            int area = heights[i]*(next[i]-prev[i]-1);
            max_area = max(area,max_area);
        }
        
        return max_area;
    }

    // 2.Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
     vector<int>nextSmallElement(vector<int>arr){
        stack<int>s;
        s.push(-1);
        vector<int>ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(s.top()!=-1 and arr[s.top()]>=arr[i]){            //because we want index that's why arr[s.top()]
                s.pop();
            } 
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>prevSmallElement(vector<int>arr){
        stack<int>s;
        s.push(-1);
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(s.top()!=-1 and arr[s.top()]>=arr[i]){            //because we want index that's why arr[s.top()]
                s.pop();
            } 
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int solve(vector<int>& heights) {
        int n = heights.size();
        vector<int>next(n);
        vector<int>prev(n);
        next = nextSmallElement(heights);
        prev = prevSmallElement(heights);
        int max_area = 0;
        for(int i=0;i<n;i++){
            if(next[i]==-1){
                next[i]=n;
            }
            int area = heights[i]*(next[i]-prev[i]-1);
            max_area = max(area,max_area);
        }
        
        return max_area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>arr(n,vector<int>(matrix[0].size(), 0));
        for(int i=0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                arr[i][j]=matrix[i][j]-'0';
            }
        }
        //1st row
        int max_area = solve(arr[0]);
        for(int i = 1;i<arr.size();i++){
            for(int j = 0;j<arr[i].size();j++){
                if(arr[i][j]>0){
                    arr[i][j]+=arr[i-1][j];
                }
            }
            int area = solve(arr[i]);
            max_area = max(max_area,area);
        }
        return max_area;
    }