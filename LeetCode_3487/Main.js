/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSum = function(nums) {
    nums.sort((a, b) => a - b);

    let sum = nums[nums.length - 1];
    let mx = sum;
    for (let i = nums.length - 2; i >= 0; i--) {
        if (nums[i] != nums[i + 1]) {
            sum += nums[i];
            mx = Math.max(mx, sum);
        }
    }
    return mx;
};