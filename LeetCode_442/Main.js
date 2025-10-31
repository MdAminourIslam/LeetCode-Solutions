/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    const answer = [];
    const cnt = new Array(nums.length + 1).fill(0);

    for (let x of nums) {
        cnt[x] += 1;
        if (cnt[x] == 2) {
            answer.push(x);
        }
    }

    return answer;
};