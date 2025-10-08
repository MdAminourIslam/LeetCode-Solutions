/**
 * @param {number[]} nums
 * @param {number[]} queries
 * @return {number[]}
 */
var answerQueries = function(nums, queries) {
    nums.sort((a, b) => a - b);

    for (let i = 1; i < nums.length; i++) {
        nums[i] += nums[i - 1];
    }
        
    const answer = [];
    for (query of queries) {
        let best = 0;
        let lo = 0;
        let hi = nums.length - 1;

        while (lo <= hi) {
            mid = Math.floor((lo + hi) / 2);

            if (nums[mid] <= query) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (nums[0] > query) {
            answer.push(0);
        } else {
            answer.push(best + 1);
        }
    }
    return answer;
};