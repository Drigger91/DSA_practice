class Solution {
public:
    bool isPossible(int mid, vector<int>& citations) {
        int ans = 0;
        for (int i : citations) {
            if (i >= mid) ans++;
        }
        return ans >= mid;
    }
    int hIndex(vector<int>& citations) {
        if (citations.size() == 1) return min(citations[0],1);
        int s = 0;
        int e = INT_MIN;
        for (int i : citations) e = max(e,i);
        int ans = 0;
        while(s <= e) {
            int mid = s + (e-s)/2;
            if (isPossible(mid, citations)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};