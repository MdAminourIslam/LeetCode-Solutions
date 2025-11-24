/**
 * @param {number[]} nums
 * @return {boolean[]}
*/
var prefixesDivBy5 = function (nums) {
    const answer = [];
    let prefix = 0;
    for (let num of nums) {
        prefix = ((prefix << 1) + num) % 5;
        answer.push(prefix === 0);
    }
    return answer;
};