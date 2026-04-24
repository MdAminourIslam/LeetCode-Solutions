/**
 * @param {string} moves
 * @return {number}
 */
var furthestDistanceFromOrigin = function(moves) {
    let mn = 0, mx = 0;
    for (let ch of moves) {
        if (ch == 'L') {
            mn -= 1;
            mx -= 1;
        } else if (ch == 'R') {
            mn += 1;
            mx += 1;
        } else {
            mn -= 1;
            mx += 1;
        }
    }
    return Math.max(Math.abs(mn), Math.abs(mx));
};