/**
 * @param {number[]} nums
 * @return {number}
 */
let lowerBound = function(nums, target) {
    let lo = 0, hi = nums.length; 
    while (lo < hi) {
        let mid = lo + parseInt((hi - lo) / 2);

        if (nums[mid] < target) {
            lo = mid + 1; 
        } else {
            hi = mid;    
        }
    }
    return lo; // nums[index] >= target
}

var triangleNumber = function(nums) {
    let n = nums.length;
    nums.sort(function(a, b) {
        return a - b;
    });
    
    let result = 0;
    for (let i = 0; i + 1 < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (!nums[i] || !nums[j]) continue;
            
            let sum = nums[i] + nums[j];
            let lo = lowerBound(nums, sum);
            result += lo - j - 1;
        }
    }
    return result;
};
