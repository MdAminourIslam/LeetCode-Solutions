/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumDifference = function (nums) {
    const n = nums.length;
    let ans = -1, premin = nums[0];
    
    for (let i = 1; i < n; ++i) {
        if (nums[i] > premin) {
            ans = (ans < nums[i] - premin ? nums[i] - premin : ans);
        } else {
            premin = nums[i];
        }
    }
    return ans;
};

console.log(maximumDifference([7, 1, 5, 4]));