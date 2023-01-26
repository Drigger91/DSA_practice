package DSA_practice.Daily;
//There are n cities connected by some number of flights. 
//You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi 
//to city toi with cost pricei.

import java.util.*;

//You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
//If there is no such route, return -1.

public class cheapestFlight {
    public static void main(String[] args) {
        int [][] flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
        int st = 0;
        int des = 3;
        int k = 1;
        int ans = findCheapestPrice(4,flights,st,des,k);
        System.out.println(ans);
    }
    public static int findCheapestPrice(int n,int[][] flights, int st, int des, int k) {
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int[] flight : flights) {
            graph.get(flight[0]).add(new int[] {flight[1], flight[2]});
        }
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[] {st, 0});
        int[] costs = new int[n];
        Arrays.fill(costs, Integer.MAX_VALUE);
        int stops = 0;
        while (!q.isEmpty() && stops <= k) {
            int size = q.size();
            while (size > 0) {
                int[] curr = q.poll();
                for (int[] neighbour : graph.get(curr[0])) {
                    int price = neighbour[1], neighbourNode = neighbour[0];
                    if (price + curr[1] >= costs[neighbourNode]) continue;
                    costs[neighbourNode] = price + curr[1];
                    q.offer(new int[] {neighbourNode, costs[neighbourNode]});
                }
                size--;
            }
            stops++;
        }
        return costs[des] == Integer.MAX_VALUE ? -1 : costs[des];
    }
}
