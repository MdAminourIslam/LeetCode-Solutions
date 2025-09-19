/**
 * @param {number[]} nums
 * @return {number}
 */
var countMaxOrSubsets = function(nums) {
    let maxOr = 0, count = 0;
    let n = nums.length;
    let total = 1 << n;

    for (let mask = 0; mask < total; mask++) {
        let cur = 0;
        for (let i = 0; i < n; i++) {
            if ((mask & (1 << i)) !== 0) {
                cur |= nums[i];
            }
        }
        if (cur > maxOr) {
            maxOr = cur;
            count = 1;
        } else if (cur === maxOr) {
            count++;
        }
    }
    return count;
};
