/**
 * @param {number[]} energy
 * @param {number} k
 * @return {number}
 */
var maximumEnergy = function(energy, k) {
    let n = energy.length;
    let answer = energy[n - 1];
    for (let i = n - 1; i >= n - k; i--) {
        let sum = 0;
        for (let j = i; j >= 0; j -= k) {
            sum += energy[j];
            answer = Math.max(answer, sum);
        }
    }
    return answer;
};