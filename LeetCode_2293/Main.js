/**
 * @param {number[]} nums
 * @return {number}
 */
var minMaxGame = function(nums) {
    let n = nums.length;

    let cur = nums;
    while (n > 1) {
        let newNums = [];

        for (let i = 0; i < parseInt(n / 2); i++) {
            if (i & 1) {
                newNums.push(Math.max(cur[2 * i], cur[2 * i + 1]));
            } else {
                newNums.push(Math.min(cur[2 * i], cur[2 * i + 1]));
            }
        }
        cur = newNums;
        n = parseInt(n / 2);
    }
    return cur[0];
};

