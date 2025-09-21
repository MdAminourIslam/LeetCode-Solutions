/**
 * @param {number[]} nums
 * @return {number}
 */
var evenNumberBitwiseORs = function(nums) {
    let answer = 0;
    for (let num of nums) {
        answer = (num & 1 ? answer : answer | num);
    }
    return answer;
};