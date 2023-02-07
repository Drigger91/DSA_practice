package DSA_practice.Daily;

import java.util.Arrays;


// You are visiting a farm that has a single row of fruit trees arranged 
// from left to right. The trees are represented by an integer array fruits where fruits[i] 
// is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. 
// There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree 
// (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.


public class totalFruits {
    public static int totalFruit(int[] fruits) {
        int ans = 0;
        int [] baskets = new int[2];
        Arrays.fill(baskets, -1);
        int [] lastIndex = new int[2];
        Arrays.fill(lastIndex, -1);
        int s = 0;
        for(int i = 0;i<fruits.length;i++){
            if(baskets[0] == -1){
                baskets[0] = fruits[i];
                lastIndex[0] = i;
                ans = Math.max(ans,i-s+1);
                continue;
            }
            else if(baskets[1] == -1 && fruits[i] != baskets[0]){
                baskets[1] = fruits[i];
                lastIndex[1] = i;
                ans = Math.max(ans,i-s+1);
                continue;
            }
            else if(fruits[i] == baskets[0] || fruits[i] == baskets[1]){
                ans = Math.max(ans,i-s+1);
                if(fruits[i] == baskets[0]){
                    lastIndex[0] = i;
                }
                else{
                    lastIndex[1] = i;
                }
                continue;
            }
            int slide = Math.min(lastIndex[0],lastIndex[1]);
            s = slide+1;
            if(s == fruits.length) break;
            if(fruits[slide] != baskets[0]){
                baskets[1] = fruits[i];
                lastIndex[1] = i;
            }else{
                baskets[0] = fruits[i];
                lastIndex[0] = i;
            }
            ans = Math.max(ans,i-s+1);
        }
        return ans;
    }
    public static void main(String[] args) {
        int [] arr = {0,1,6,6,4,4,6};
        System.out.println("Ans : " + totalFruit(arr));
    }
}
