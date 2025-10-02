/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var maxBottlesDrunk = function(numBottles, numExchange) {
    let emptyBottles = numBottles;
    let answer = numBottles;

    while (emptyBottles >= numExchange) {
        answer += 1;   
        emptyBottles -= numExchange;
        numExchange += 1;
        emptyBottles += 1;
    }
    return answer;
};