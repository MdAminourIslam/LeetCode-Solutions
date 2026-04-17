function reverseNumber(n) {
    let revNum = 0;
    while (n > 0) {
        revNum = revNum * 10 + (n % 10);
        n = Math.floor(n / 10);
    }
    return revNum;
}


/**
 * @param {number[]} nums
 * @return {number}
 */
var minMirrorPairDistance = function(nums) {
    const indx = {};
    const n = nums.length;
    let answer = n;

    for (let i = 0; i < n; i++) {
        if (nums[i] in indx) {
            answer = Math.min(answer, i - indx[nums[i]] + 1);
        }
        indx[reverseNumber(nums[i])] = i + 1;
    }

    return answer === n ? -1 : answer;
};


