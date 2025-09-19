/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxFrequency = function(nums, k) {
    nums.sort((a, b) => a - b);
    const n = nums.length;

    const prefix = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    let ans = 1;

    for (let i = 1; i < n; i++) {
        let lo = 1, hi = i + 1, best = 1;

        while (lo <= hi) {
            let mid = Math.floor((lo + hi) / 2);
            let total = prefix[i + 1] - prefix[i + 1 - mid];
            let required = nums[i] * mid;

            if (required - total <= k) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        ans = Math.max(ans, best);
    }

    return ans;
};
