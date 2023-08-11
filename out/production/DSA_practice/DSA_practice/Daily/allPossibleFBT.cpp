##include<bits/stdc++.h>
using namespace std;

vector<TreeNode*> solve(int n, vector<vector<TreeNode*>>& dp) {
        if (n % 2 == 0) {
            return {};
        }
        if (n == 1) {
            return {new TreeNode(0)};
        }
        if (dp[n].size() != 0) {
            return dp[n];
        }
        vector<TreeNode*> ans;
        for (int i = 1;i<n;i+=2) {
            vector<TreeNode*> left_vector = solve(i,dp);
            vector<TreeNode*> right_vector = solve(n-i-1, dp);
            for (TreeNode* left : left_vector) {
                for(TreeNode* right : right_vector) {
                    TreeNode* root = new TreeNode(0, left, right);
                    ans.push_back(root);
                }
            }
        }
        return dp[n] = ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp(n+1);
        return solve(n, dp);
    }