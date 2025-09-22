/**
 * @param {number[]} nums
 * @return {number}
 */
var maxFrequencyElements = function(nums) {
    const cnt = Array(101).fill(0); 

    for (let num of nums) {
        cnt[num]++;
    }

    let mx = Math.max(...cnt);

    let result = 0;
    for (let f of cnt) {
        if (f == mx) {
            result += f;
        }
    }

    return result;
};

console.log(maxFrequencyElements([1,2,2,3,1,4]))
