// Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
//  The remaining elements of nums are not important as well as the size of nums.
// Return k.

// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).
#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int> nums, int val) {
    int count = 0;
    int pos = 0;
    for (int i = 0;i < nums.size(); i++) {
        if (nums[i] != val) {
            count++;
            swap(nums[i], nums[pos++]);
        }
    }
    return count;
}