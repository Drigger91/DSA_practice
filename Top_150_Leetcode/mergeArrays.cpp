// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
//representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(int m, int n, vector<int> nums1, vector<int> nums2) {
    vector<int> result;
    int i = 0,j = 0;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            result.push_back(nums1[i++]);
        } else {
            result.push_back(nums2[j++]);
        }
    }
    while (i < m) result.push_back(nums1[i++]);
    while (j < n) result.push_back(nums2[j++]);
    nums1 = result;
}

