package DSA_practice.Daily;

public class permutationString {
    public static boolean check(int[] a,int[] b){
        for(int i = 0;i<26;i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    public static boolean checkInclusion(String s1, String s2) {
        int[] count_s1 = new int[26];
        int[] count_s2 = new int[26];
        for(int i = 0;i<s1.length();i++){
            char c = s1.charAt(i);
            count_s1[c-'a']++;
        }
        int i = 0;
        int window = s1.length();
        while(i < window && i < s2.length()){
            count_s2[s2.charAt(i) - 'a']++;
            i++;
        }
        if(check(count_s1,count_s2)) return true;
        while(i < s2.length()){
            //new char freq ++;
            count_s2[s2.charAt(i) - 'a']++;
            //prev char freq --;
            count_s2[s2.charAt(i-window) - 'a']--;
            if(check(count_s1,count_s2)) return true;
            i++;
        }
        return false;
    }
    public static void main(String[] args) {
        String s1 = "ab";
        String s2 = "alotofcharachtersandbapremutation";
        boolean ans = checkInclusion(s1, s2);
        System.out.println(ans);
    }
}
