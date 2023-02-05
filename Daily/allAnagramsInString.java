package DSA_practice.Daily;
import java.util.*;

// Given two strings s and p, 
// return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]

public class allAnagramsInString {
    public static boolean checkZeros(int[] count){
        for(int i : count) if(i != 0) return false;
        return true;
    }
    public static List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans = new ArrayList<>();
        if(s.length() < p.length()) return ans;
        int [] count = new int[26];
        for(int i = 0;i<p.length();i++){
            count[p.charAt(i) - 'a']++;
            count[s.charAt(i) - 'a']--;
        }
        if(checkZeros(count)) ans.add(0);
        int window = p.length();
        for(int i = 1;i<s.length();i++){
            if(i+window > s.length()) break;
            count[s.charAt(i-1) - 'a']++;
            count[s.charAt(i+window-1) - 'a']--;
            if(checkZeros(count)) ans.add(i);
        }
        return ans;
    }
    public static void main(String[] args) {
        String s = "cbaebabacd";
        String p = "abc";
        System.out.println("ans : " + findAnagrams(s, p));
    }
}
