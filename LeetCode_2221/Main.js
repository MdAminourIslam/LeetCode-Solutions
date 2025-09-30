/**
 * @param {number[]} nums
 * @return {number}
 */
var triangularSum = function(nums) {
    let prev = nums;
    let n = nums.length;
    let cur = [];

    while (n > 1) {
        cur = [];
        for (let i = 0; i + 1 < prev.length; i++) {
            cur.push((prev[i] + prev[i + 1]) % 10);
        }
        n -= 1;
        prev = cur;
    }
    return prev[0];
};

console.log(triangularSum([1,2,3,4,5]));
console.log(triangularSum([5]));