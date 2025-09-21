/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxTotalValue = function(nums, k) {
    let mx = Math.max(...nums);
    let mn = Math.min(...nums);
    return (mx - mn) * k;
};