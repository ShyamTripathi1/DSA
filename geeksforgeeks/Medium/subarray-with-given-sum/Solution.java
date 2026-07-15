// Time Complexity: O(N)
// Space Complexity: O(1)
import java.util.ArrayList;

class Solution {
    static ArrayList<Integer> subarraySum(int[] arr, int n, int s) {
        int start = 0;
        int currentSum = 0;
        ArrayList<Integer> res = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            currentSum += arr[i];
            
            while (currentSum > s && start < i) {
                currentSum -= arr[start];
                start++;
            }
            
            if (currentSum == s) {
                res.add(start + 1); // 1-based indexing
                res.add(i + 1);
                return res;
            }
        }
        res.add(-1);
        return res;
    }
}