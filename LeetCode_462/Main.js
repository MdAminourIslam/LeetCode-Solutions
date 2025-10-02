/**
 * @param {number[]} nums
 * @return {number}
 */

var minMoves2 = function(nums) {
    nums.sort((a, b) => a - b);
    let mid = nums[parseInt(nums.length / 2)];

    let operation = 0;
    for (let num of nums) {
        operation += Math.abs(num - mid);
    }
    return operation;
};