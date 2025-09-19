
/**
 * @param {number[]} nums
 * @return {number}
 */

function max(a, b) {
    return a > b ? a : b;
}

var maximumLength = function(nums) {
    let len = 0;
    let mod = 0;
    let odd = 0;

    for (let i = 0; i < nums.length; i++) {
        let x = nums[i];
        if (x % 2 != mod) {
            len += 1;
            mod = x & 1;
        }
        odd += (x & 1);
    }

    let mx = max(len, odd);
    mx = max(mx, nums.length - odd);

    len = 0, mod = 1;
    
    for (let i = 0; i < nums.length; i++) {
        let x = nums[i];
        if (x % 2 != mod) {
            len += 1;
            mod = x & 1;
        }
    }

    return max(mx, len);
};