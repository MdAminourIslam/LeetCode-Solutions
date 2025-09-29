/**
 * @param {number} n
 * @return {number}
 */
var numberOfCuts = function(n) {
    if (n == 1) return 0;
    return n & 1 ? n : parseInt(n / 2);
};

console.log(numberOfCuts(4));
console.log(numberOfCuts(3));