package DSA_practice.Daily;

public class Tribonacci {
    public static int tribonacci(int n) {
        int first = 0;
        int second = 1;
        int third = 1;
        if(n == 2) return 1;
        if(n == 0 || n == 1) return n;
        int ans = 0;
        for(int i = 3;i<=n;i++){
            ans = (first+second+third);
            first = second;
            second = third;
            third = ans;
        }
        return ans;
    }
    public static void main(String[] args) {
        int n = 37;
        int ans = tribonacci(n);
        assert tribonacci(4) == 4;
        assert tribonacci(0) == 0;
        System.out.println("Ans : " + ans);
    }
}
