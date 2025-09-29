/**
 * @param {number[]} nums
 * @return {number[]}
 */
var lastVisitedIntegers = function(nums) {
    const seen = [], ans = [];
    let consecutive = 0;
    for (let num of nums) {
        if (num >= 1) {
            seen.unshift(num);
            consecutive = 0;
        } else {
            consecutive += 1;
            if (consecutive > seen.length) {
                ans.push(-1);
            } else {
                ans.push(seen[consecutive - 1]);
            }
        }
    }
    return ans;
};

console.log(lastVisitedIntegers([1,2,-1,-1,-1]));
console.log(lastVisitedIntegers([1,-1,2,-1,-1]));