
class Solution {
    public int findLucky(int[] arr) {
        int[] cnt = new int[501];
        
        for (int i = 0; i <= 500; i++) {
            cnt[i] = 0;
        }

        for (int i = 0; i < arr.length; i++) {
            cnt[arr[i]]++;
        }
    
        for (int i = 500; i >= 1; i--) {
            if (cnt[i] == i) {
                return i;
            }
        }
        return -1;
    }
}