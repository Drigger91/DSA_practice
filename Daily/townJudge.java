package DSA_practice.Daily;


// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
//example - Input: n = 2, trust = [[1,2]]
// Output: 2

public class townJudge{
    public static int findJudge(int n , int[][] trust) {
        int[] ans = new int[n];
        for(int[] arr : trust){
            ans[arr[0]-1]--;
            ans[arr[1]-1]++;
        }
        for(int i = 0;i<ans.length;i++){
            if(ans[i] == n-1) return i+1;
        }
        return -1;
    }
    public static void main(String[] args) {
        int[][]trust = {{1,2}};
        System.out.println(findJudge(2, trust));
    }
}