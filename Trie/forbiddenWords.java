package DSA_practice.Trie;
import java.util.*;
public class forbiddenWords {
    public static class Node {
        List<Node> child;
        boolean isTerminal;
        public Node() {
            child = new ArrayList<>();
            for (int i = 0;i<26;i++) {
                child.add(null);
            }
            isTerminal = false;
        }

    }
   static Node root = new Node();
    public static void insert(String s) {
        Node curr = root;
        for (int i = 0;i < s.length(); i++) {
            int idx = s.charAt(i) - 'a';
            if (curr.child.get(idx) == null) curr.child.add(idx, new Node());
            curr = curr.child.get(idx);
        }
        curr.isTerminal = true;
    }
    public static boolean search(String s, int i, int j) {
        Node curr = root;
        while (i <= j) {
            int idx = s.charAt(i) - 'a';
            if (curr.child.get(idx) == null) return false;
            curr = curr.child.get(idx);
            if (curr.isTerminal) return true;
            i++;
        }
        return false;
    }

    public static int longestValidSubstring(String word, List<String> forbidden) {
        Node root = new Node();
        for (String str : forbidden) {
            insert(str);
        }
        int ans = 0;
        int len = word.length() - 1;
        for (int i = word.length() - 1; i >= 0; i--) {
            while(i <= len && search(word, i, len)) len--;
            ans = Math.max(ans, len - i + 1);
        }
        return ans;
    }
    public static void main(String[] args) {
        List<String> ls = List.of("aaa","cb");
        int ans = longestValidSubstring("cbaaaabc", ls);
        System.out.println(ans);
    }
}
