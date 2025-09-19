/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var numSubseq = function(nums, target) {
    const MOD = 1e9 + 7;
    nums.sort((a, b) => a - b);
    const n = nums.length;

    const powerOfTwo = new Array(n);
    powerOfTwo[0] = 1;
    for (let i = 1; i < n; i++) {
        powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % MOD;
    }

    let left = 0, right = n - 1;
    let subSequence = 0;

    while (left <= right) {
        if (nums[left] + nums[right] > target) {
            right--;
        } else {
            subSequence = (subSequence + powerOfTwo[right - left]) % MOD;
            left++;
        }
    }

    return subSequence;  
};

const nums = [3,5,6,7], target = 9;

console.log(numSubseq(nums, target))