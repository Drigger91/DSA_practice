package DSA_practice.Daily;
import java.util.*;

public class rangeQuery {
    private Map<Integer,List<Integer>> map = new HashMap<>();
    public rangeQuery(int [] arr){
        for(int i = 0;i<arr.length;i++){
            List<Integer> list = map.getOrDefault(arr[i], new ArrayList<>());
            list.add(i);
            map.put(arr[i], list);
        }
    }
    private int upperBound(List<Integer> list, int index){
        int l = 0;
        int r = list.size() - 1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(list.get(mid) >= index){
                if(list.get(mid) == index){
                    return mid;
                }
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        return ans;
    }
    
    private int lowerBound(List<Integer> list, int index){
        int l = 0;
        int r = list.size() - 1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(list.get(mid) <= index){
                if(list.get(mid) == index){
                    return mid;
                }
                
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        
        return ans;
    }
    public int query(int left, int right, int value) {
        if(map.get(value).size() == 0) return 0;
        int start = lowerBound(map.get(value), left);
        int end = upperBound(map.get(value), right);
        if(start == -1 || end == -1) return 0;
        return end - start + 1;
    }
    public static void main(String[] args) {
        
    }
}
