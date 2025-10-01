/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function(numBottles, numExchange) {
    let drink = numBottles;

    while (numBottles >= numExchange) {
        let rem = numBottles % numExchange;
        let water = parseInt(numBottles / numExchange);
        drink += water;
        numBottles = water + rem;
    }
    return drink;
};

console.log(numWaterBottles(15, 4));
console.log(numWaterBottles(9, 3));
