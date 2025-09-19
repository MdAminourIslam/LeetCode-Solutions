
class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        int n = startTime.length;
        int[] pre = new int[n];
        
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += endTime[i] - startTime[i];
            pre[i] = cur;
        }

        int res = 0;
        for (int i = k - 1; i < n; i++) {
            int left = (i + 1 == k) ? 0 : endTime[i - k];
            int right = (i + 1 == n) ? eventTime : startTime[i + 1];
            int sum = (i + 1 == k) ? pre[i] : pre[i] - pre[i - k];

            res = Math.max(res, right - left - sum);
        }

        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        
    }
}
