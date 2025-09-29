/**
 * @param {number} n
 * @return {boolean}
 */
var isThree = function(n) {
    let divisorCount = 0;
    for (let i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisorCount += 1;
            if (n / i != i) {
                divisorCount += 1;
            }
        }
        if (divisorCount > 3) {
            return false;
        }
    }
    return divisorCount == 3;
};

console.log(isThree(2));
console.log(isThree(4));