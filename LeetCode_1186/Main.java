package LeetCode_1186;

class Solution {
    public int maximumSum(int[] arr) {
        int n = arr.length;
        int[] pre_max = new int[n];
        int[] suf_max = new int[n];
        int cur_sum = 0;
        
        int mx = maxElement(arr);

        for (int i = 0; i < n; i++) {
            cur_sum += arr[i];
            if (cur_sum < 0) {
                cur_sum = 0;
            } else {
                mx = Math.max(mx, cur_sum);
            }
            pre_max[i] = cur_sum;
        }

        cur_sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur_sum += arr[i];
            if (cur_sum < 0) {
                cur_sum = 0;
            }
            suf_max[i] = cur_sum;
        }

        for (int i = 1; i + 1 < n; i++) {
            int sum = (pre_max[i - 1] + suf_max[i + 1] > 0 ? pre_max[i - 1] + suf_max[i + 1] : Integer.MIN_VALUE);
            mx = Math.max(mx, sum);
        }

        return mx;
    }

    private int maxElement(int[] arr) {
        int mx = arr[0];
        for (int val : arr) {
            mx = Math.max(mx, val);
        }
        return mx;
    }
}


public class Main {
    public static void main(String[] args) {
        
    }
}
