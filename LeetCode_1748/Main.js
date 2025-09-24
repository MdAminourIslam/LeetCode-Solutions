/**
 * @param {number[]} nums
 * @return {number}
 */
var sumOfUnique = function(nums) {
    const cnt = [];
    for (let num of nums) {
        cnt[num] = cnt[num] == undefined ? 1 : cnt[num] + 1;
    }
    
    let sum = 0;
    for (let i = 1; i <= 100; i++) {
        sum = cnt[i] == 1 ? sum + i : sum;
    }
    return sum;
};