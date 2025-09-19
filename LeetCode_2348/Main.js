/**
 * @param {number[]} nums
 * @return {number}
 */
var zeroFilledSubarray = function(nums) {
    let cnt = 0, ans = 0;
    for (let num of nums) {
        if (num === 0) {
            cnt++;
        } else {
            ans += (cnt * (cnt + 1)) / 2;
            cnt = 0;
        }
    }
    ans += (cnt * (cnt + 1)) / 2;
    return ans;
};
