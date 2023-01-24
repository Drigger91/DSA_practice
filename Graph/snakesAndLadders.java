package DSA_practice.Graph;

import java.util.LinkedList;
import java.util.Queue;

//Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
//Output: 4
//board is like : 
// 7 8 9
// 6 5 4
// 1 2 3
public class snakesAndLadders {
    private static int[] getLocation(int newPos,int n) {
        int row = n - ((newPos - 1)/n )- 1;
        int col = (newPos-1)%n;
        if(row%2 == n % 2){
            col = n - col - 1;
        }
        int[] ans = {row,col};
        return ans;
    }
    public static int snakesAndLadders(int[][] board) {
        int n = board.length;
        boolean [][] vis = new boolean[n][n];
        Queue<Integer> q = new LinkedList<>();
        q.offer(1);
        int ans = 0;
        while(!q.isEmpty()){
            int chances = q.size();
            for(int i = 0;i<chances;i++){
                int pos = q.poll();
                if(pos == n*n) return ans;
                for(int j = 1;j<=6;j++){
                    int newPos = pos + j;
                    if(newPos > n*n) break;
                    int [] location = getLocation(newPos,n);
                    int row = location[0];
                    int col = location[1];
                    if(!vis[row][col]){
                        vis[row][col] = true;
                        if(board[row][col] != -1) q.add(board[row][col]);
                        else q.add(newPos);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
    public static void main(String[] args) {
        int [][] board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
        int ans = snakesAndLadders(board);
        System.out.println(ans);
    }
}
