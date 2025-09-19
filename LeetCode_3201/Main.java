
class Solution {
    public int maximumLength(int[] nums) {
        int len = 0;
        int mod = 0;
        int odd = 0;
        for (int x : nums) {
            if (x % 2 != mod) {
                len += 1;
                mod = x & 1;
            }
            odd += (x & 1);
        }

        int mx = Math.max(len, odd);
        mx = Math.max((int)nums.length - odd, mx);

        len = 0;
        mod = 1;
        for (int x : nums) {
            if (x % 2 != mod) {
                len += 1;
                mod = x & 1;
            }
        }
        return Math.max(mx, len);
    }
}

public class Main {
    public static void main(String[] args) {
        
    }
}
