class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] cnt = new int[101];
        for (int num : nums) {
            cnt[num] += 1;
        }
        int sum = 0;
        int mx = 0;
        for (int c : cnt) {
            mx = Math.max(mx, c);
        }
        for (int c : cnt) {
            sum = (c == mx ? sum + c : sum);
        }
        return sum;
    }
}