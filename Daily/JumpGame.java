package DSA_practice.Daily;
import java.util.*;
public class JumpGame {
    public static int jump(int[] nums) {
        int [] dp = new int[nums.length];
        Arrays.fill(dp,Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i = 0;i<nums.length;i++){
            for(int j = 0;j<=nums[i];j++){
                if(i+j >= nums.length) break;
                dp[i+j] = Math.min(dp[i] + 1, dp[i+j]);
            }
        }
        return dp[nums.length-1];
    }
    public static void main(String[] args) {
        int[] nums = {2,3,1,1,4};
        System.out.println("Ans : " + jump(nums));
    }
}
