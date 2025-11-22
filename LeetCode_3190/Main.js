/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function(nums) {
    var cnt = 0;
    for (let num of nums) {
        if (num % 3) {
            cnt += 1;
        }
    }
    return cnt;
};