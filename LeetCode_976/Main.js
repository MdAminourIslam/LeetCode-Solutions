/**
 * @param {number[]} nums
 * @return {number}
 */
var largestPerimeter = function(nums) {
    let n = nums.length;
    nums.sort(function(a, b) {
        return a - b;
    });

    let mx = 0;
    for (let i = 0; i + 2 < n; i++) {
        if (nums[i] + nums[i + 1] > nums[i + 2]) {
            mx = nums[i] + nums[i + 1] + nums[i + 2];
        }
    }
    return mx;
};