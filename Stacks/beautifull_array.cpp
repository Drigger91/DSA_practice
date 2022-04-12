#include<bits/stdc++.h>

// You are given a 0-indexed integer array nums. The array nums is beautiful if:

// nums.length is even.
// nums[i] != nums[i + 1] for all i % 2 == 0.
// Note that an empty array is considered beautiful.

// You can delete any number of elements from nums. When you delete an element, all the elements to the right of the deleted element will be shifted one unit to the left to fill the gap created and all the elements to the left of the deleted element will remain unchanged.

// Return the minimum number of elements to delete from nums to make it beautiful.

int minDeletion(vector<int>& nums) {
        if(nums.size() == 0 or nums.size() == 1){
            return nums.size();
        }
        queue<int> q;
        for(auto i : nums){
            q.push(i);
        }
        int ans = 0;
        int count = 0;
        vector<int> temp;
        while(q.size() > 1){
            int first = q.front();
            q.pop();
            int second = q.front();
            if(count % 2 == 0 or count == 0){
                if(first == second){
                    ans+=1;
                }
                else{
                    count+=1;
                    temp.push_back(first);
                }
            }
            else{
                temp.push_back(first);
                count+=1;
            }
        }
        temp.push_back(q.front());
        return temp.size()%2 == 0 ? ans:ans+1;
    }
