/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {
    let mx = Math.max(...nums);
    let ans = 1, cnt = 0;

    for (let num of nums) {
        if (num == mx) {
            cnt += 1;
            ans = Math.max(ans, cnt);
        } else {
            cnt = 0;
        }
    }
    
    return ans;
};