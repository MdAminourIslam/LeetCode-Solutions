/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumUniqueSubarray = function(nums) {
    let n = nums.length;
    let cnt = [];

    for (let i = 0; i <= 10000; i++) {
        cnt[i] = 0;
    }

    //const cnt = new Array(10001).fill(0);
    //const cnt = Array(10001).fill(0);
    // new is otional

    let pre_sum = [];
    pre_sum[0] = 0;

    for (let i = 0; i < n; i++) {
        pre_sum[i + 1] = pre_sum[i] + nums[i];
    }
    let res = 0;
    for (let i = 1, j = 1; i <= n; i++) {
        while (cnt[nums[i - 1]] > 0) {
            cnt[nums[j - 1]]--;
            j += 1;
        }
        cnt[nums[i - 1]]++;
        res = Math.max(res, pre_sum[i] - pre_sum[j - 1]);
    }
    return res;
};

const nums = [4,2,4,5,6];
console.log(maximumUniqueSubarray(nums));