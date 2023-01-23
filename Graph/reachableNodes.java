package DSA_practice.Graph;
import java.util.*;
//There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

// You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between 
//nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.

// Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.

// Note that node 0 will not be a restricted node.

//Example - n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]

public class reachableNodes {
    public static int dfs(List<List<Integer>> graph,boolean[] vis, Set<Integer> set,int i){
        if(set.contains(i)) return 0;
        int ans = 0;
        if(vis[i] == true) return ans;
        vis[i] = true;
        ans++;
        for(int ngb : graph.get(i)){
            if(vis[ngb]) continue;
            ans += dfs(graph, vis, set, ngb);
        }
        return ans;
    }
    public static int reachableNodes(int n, int[][] edges, int[] restricted) {
        List<List<Integer>> graph = new ArrayList<>(n);
        for(int i = 0;i<n;i++){
            graph.add(i, new ArrayList<>());
        }
        for(int [] arr : edges){
            graph.get(arr[1]).add(arr[0]);
            graph.get(arr[0]).add(arr[1]);
        }
        boolean[] vis = new boolean[n];
        Set<Integer> set = new HashSet<>();
        for(int i : restricted){
            set.add(i);
        }
        int ans = dfs(graph,vis,set,0);
        return ans;
    }
    public static void main(String[] args) {
        System.out.println("asfs");
        int[][] edges = {{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}};
        int[] restricted = {4,5};
        int ans = reachableNodes(7,edges,restricted);
        System.out.println("Answer : " + ans);
    }
}
