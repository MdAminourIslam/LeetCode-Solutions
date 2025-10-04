/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let answer = 0;
    let lo = 0, hi = height.length - 1;
    while (lo <= hi) {
        answer = Math.max(answer, (hi - lo + 1) * Math.min(height[lo], height[hi]));
        
        if (height[lo] <= height[hi]) {
            lo += 1;
        } else {
            hi -= 1;
        }
    }
    return answer;
};