class Solution {
    public int evenNumberBitwiseORs(int[] nums) {
        int answer = 0;
        for (int i = 0; i < nums.length; i++) {
            answer = (nums[i] % 2 == 1 ? answer : answer | nums[i]);
        }
        return answer;
    }
}

