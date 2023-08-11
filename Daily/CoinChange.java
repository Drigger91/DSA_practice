package DSA_practice.Daily;

import java.util.Arrays;

public class CoinChange {
    public int helper(int[] coins, int remaining, int i, int[][] dp) {
        //base cases
        if (i >= coins.length) return 0;
        if (dp[i][remaining] != -1) return dp[i][remaining];
        if (remaining == 0) return 1;

        //main logic
        int take = 0;
        if (remaining >= coins[i]) {
            take = helper(coins, remaining - coins[i], i+1, dp);
        }
        int notTake = helper(coins, remaining, i+1, dp);

        return dp[i][remaining] = take + notTake;
    }
    public int change(int amount, int[] coins) {
        int[][] dp = new int[coins.length][amount+1];
        for (int[] arr : dp) {
            Arrays.fill(arr,-1);
        }
        return helper(coins, amount, 0, dp);
    }
}
