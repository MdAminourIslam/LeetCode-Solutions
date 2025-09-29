/**
 * @param {number[]} piles
 * @return {number}
 */
var maxCoins = function(piles) {
    piles.sort(function(a, b) {
        return a - b;
    });

    let moves = parseInt(piles.length / 3);
    let indx = piles.length - 2;
    let coins = 0;

    while (moves) {
        coins += piles[indx];
        indx -= 2;
        moves -= 1;
    }
    return coins;
};
console.log(maxCoins([2, 4, 5]));
console.log(maxCoins([2,4,1,2,7,8]));
console.log(maxCoins([9,8,7,6,5,1,2,3,4]));
