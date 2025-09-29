/**
 * @param {number[]} nums
 * @return {number}
 */

const isDecreasing = (nums, dec) => {
    let n = nums.length;
    dec[n - 1] = true;
    for (let i = n - 2; i >= 0; i--) {
        if (nums[i] > nums[i + 1] && dec[i + 1]) {
            dec[i] = true;
        } else {
            dec[i] = false;
            break;
        }
    }
};

const suffixSumOfArray = (nums, suffix) => {
    let len = nums.length;
    suffix[len - 1] = nums[len - 1];

    for (let i = len - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + nums[i];  
    }
};

var splitArray = function(nums) {
    const dec = [];
    let n = nums.length;
    const suffix = [];

    for (let i = 0; i < n; i++) {
        dec.push(false);
        suffix.push(0);
    }

    isDecreasing(nums, dec);
    suffixSumOfArray(nums, suffix);

    let minimum = 1e12;
    let prefixSum = nums[0];
    let inc = true;

    for (let i = 1; i < n; i++) {
        if (dec[i] && inc) {
            minimum = Math.min(minimum, Math.abs(prefixSum - suffix[i]));
        }
        
        if (nums[i] <= nums[i - 1]) {
            inc = false;
        }
        prefixSum += nums[i];
    }
    return minimum === 1e12 ? -1 : minimum;
};

console.log(splitArray([1, 3, 2])); 
