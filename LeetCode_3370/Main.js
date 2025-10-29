/**
 * @param {number} n
 * @return {number}
 */
var smallestNumber = function(n) {
    let last = parseInt(Math.log2(n));
    return (1 << (last + 1)) - 1;
};
