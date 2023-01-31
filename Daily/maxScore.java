package DSA_practice.Daily;

import java.util.Arrays;

public class maxScore {
    public static int helper(int[][] pairs,int i,int[][]dp,int prev){
        if(i == pairs.length) return 0;
        if(dp[i][prev] != 0) return dp[i][prev];
        int take = 0;
        if(pairs[i][1] >= prev){
            take = pairs[i][0] + helper(pairs,i+1,dp,pairs[i][1]);
        }
        int notTake = helper(pairs,i+1,dp,prev);
        return dp[i][prev] = Math.max(take, notTake);
    }
    public static int bestTeamScore(int[] scores, int[] ages) {
        int n = ages.length;
        int [][] pairs = new int[n][n];
        for(int i = 0;i<n;i++){
            int [] pair = new int [2];
            pair[0] = scores[i];
            pair[1] = ages[i];
            pairs[i] = pair;
        }
        Arrays.sort(pairs,(a,b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        // for(int i = 0;i<n;i++){
        //     System.out.println(pairs[i][0] + " " + pairs[i][1]);
        // }
        int [][] dp = new int[n][1001];
        // int [] dpVal = new int[1001];
        // Arrays.fill(dpVal,-1);
        // Arrays.fill(dp, dpVal);
        int ans = helper(pairs,0,dp,0);
        return ans;
    }
    public static void main(String[] args) {
        int [] scores = {1,3,5,10,15};
        int [] ages = {1,2,3,4,5};
        int ans = bestTeamScore(scores, ages);
        System.out.println(ans);
    }
}
