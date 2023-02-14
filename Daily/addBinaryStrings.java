package DSA_practice.Daily;

public class addBinaryStrings {
    public static String addBinary(String a, String b) {
        StringBuilder ans = new StringBuilder();
        int carry = 0;
        int i = a.length()-1;
        int j = b.length()-1;
        while(i>=0 && j>=0){
            if(a.charAt(i) == '1' && b.charAt(j) == '1'){
                ans.append(carry == 0 ? '0' : '1');
                carry = 1;
            }
            else if(a.charAt(i) == '0' && b.charAt(j) == '0'){
                ans.append(carry == 0 ? '0' : '1');
                carry = 0; 
            }
            else{
                if(carry == 1){
                    ans.append('0');
                }else{
                    ans.append('1');
                }
            }
            i--;
            j--;
        }
        while(i >= 0){
            if(a.charAt(i) == '1'){
                ans.append(carry == 0 ? '1' : '0');
            }else{
                ans.append(carry == 0 ? '0' : '1');
                carry = 0;
            }
            i--;
        }
        while(j >= 0){
            if(b.charAt(j) == '1'){
                ans.append(carry == 0 ? '1' : '0');
            }else{
                ans.append(carry == 0 ? '0' : '1');
                carry = 0;
            }
            j--;
        }
        if(carry == 1) ans.append('1');
        ans.reverse();
        return ans.toString();
    }
    public static void main(String[] args) {
        String a = "110010";
        String b = "10111";
        System.out.println(addBinary(a, b));
    }
}
