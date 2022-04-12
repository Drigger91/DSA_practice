#include<bits/stdc++.h>
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

int trap(vector<int>& height) {
        //brute
        int n = height.size();
        vector<int>left(n);
        vector<int>right(n);
        left[0] = height[0];
        right[n-1]=height[n-1];
        for(int i = 1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
            right[n-i-1] = max(right[n-i],height[n-i-1]);
        }
        int area = 0;
        for(int i=0;i<n;i++){
            area += min(left[i],right[i])-height[i];
        }
        return area;
    
    }