
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumLength = function(nums, k) {
    const dp = Array.from({ length: k }, () => new Array(k).fill(0));
    for (let i = 0; i < k; i++) {
        for (let j = 0; j < k; j++) {
            dp[i][j] = 0;
        }
    }
    let res = 2;
    for (let num of nums) {
        num %= k;
        for (let prev = 0; prev < k; prev++) {
            dp[prev][num] = dp[num][prev] + 1;
            res = Math.max(res, dp[prev][num]);
        }
    }
    return res;
};