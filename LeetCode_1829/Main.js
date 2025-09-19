/**
 * @param {number[]} nums
 * @param {number} maximumBit
 * @return {number[]}
 */
var getMaximumXor = function(nums, maximumBit) {
    const mx = (1 << maximumBit) - 1;
    const n = nums.length;
    const pre_xor = Array(n).fill(0);
    const ans = Array(n).fill(0);

    pre_xor[0] = nums[0];
    for (let i = 1; i < n; i++) {
        pre_xor[i] = pre_xor[i - 1] ^ nums[i];
    }

    for (let i = 0; i < n; i++) {
        ans[i] = pre_xor[n - i - 1] ^ mx;
    }

    return ans;
};
