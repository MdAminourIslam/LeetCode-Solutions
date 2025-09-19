package LeetCode_2210;

public class Main {

    public static void main(String[] args) {
        
    }
}

class Solution {
    public int countHillValley(int[] nums) {
        int n = nums.length;
        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] != nums[i - 1]) {
                int left = nums[i], right = nums[i];

                int indx = i;
                while (indx >= 0) {
                    if (nums[indx] != nums[i]) {
                        left = nums[indx];
                        break;
                    }
                    indx--;
                }

                indx = i;
                while (indx < n) {
                    if (nums[indx] != nums[i]) {
                        right = nums[indx];
                        break;
                    }
                    indx++;
                }

                if ((nums[i] > left && nums[i] > right) || (nums[i] < left && nums[i] < right)) {
                    //System.out.println("i = " + i + " and " + nums[i]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
