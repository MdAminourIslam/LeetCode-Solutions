/**
 * @param {number[][]} fruits
 * @param {number} startPos
 * @param {number} k
 * @return {number}
 */
var maxTotalFruits = function(fruits, startPos, k) {
    const MX = 200002;
    const preSum = Array(MX).fill(0);

    // Fill fruit amounts
    for (let i = 0; i < fruits.length; i++) {
        preSum[fruits[i][0] + 1] = fruits[i][1];
    }

    // Build prefix sum
    for (let i = 1; i < MX; i++) {
        preSum[i] += preSum[i - 1];
    }

    let ans = 0;
    startPos += 1;

    // Move left first, then right
    for (let i = 0; i <= k; i++) {
        let left = Math.max(startPos - i, 1);
        let right = Math.min(left + (k - i), 200001);
        ans = Math.max(ans, preSum[right] - preSum[left - 1]);
    }

    // Move right first, then left
    for (let i = 0; i <= k; i++) {
        let right = Math.min(startPos + i, 200001);
        let left = Math.max(right - (k - i), 1);
        ans = Math.max(ans, preSum[right] - preSum[left - 1]);
    }

    return ans;
};


const fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4;
console.log(maxTotalFruits(fruits, startPos, k));