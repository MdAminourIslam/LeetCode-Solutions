/**
 * @param {number} n
 * @return {number}
 */
var numberOfCuts = function(n) {
    return n & 1 ? n : parseInt(n / 2);
};

console.log(numberOfCuts(4));
console.log(numberOfCuts(3));