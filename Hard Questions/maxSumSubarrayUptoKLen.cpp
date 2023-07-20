// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>& arr, int k) {
      int n = arr.size();
    vector<int> prefixSum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    int globalMax = INT_MIN;
    deque<int> dq;

    for (int i = 0; i <= n; ++i) {
        if (!dq.empty() && i - dq.front() > k) {
            dq.pop_front();
        }
        while (!dq.empty() && prefixSum[i] < prefixSum[dq.back()]) {
            dq.pop_back();
        }

        if (!dq.empty()) {
            int currentMax = prefixSum[i] - prefixSum[dq.front()];
            globalMax = max(globalMax, currentMax);
        }

        dq.push_back(i);
    }

    return globalMax;
}
int main() {
    // Write C++ code here
    vector<int> arr = {-3,4,3,-9,2,5};
    int ans = helper(arr, 4);
    cout<<ans<<endl;
    return 0;
}