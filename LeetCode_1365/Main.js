/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    const arr = [...nums];
    arr.sort((a, b) => a - b);

    const cnt = new Array(101).fill(-1);

    for (let i = 0; i < arr.length; i++) {
        if (cnt[arr[i]] == -1) {
            cnt[arr[i]] = i;
        }
    }
    const answer = [];
    for (let num of nums) {
        answer.push(cnt[num]);
    }
    return answer;
};

console.log(smallerNumbersThanCurrent(nums = [8,1,2,2,3]));