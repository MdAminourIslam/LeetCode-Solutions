/**
 * @param {string} colors
 * @return {boolean}
 */
var winnerOfGame = function(colors) {
    let alice = 0, bob = 0;
    let cnta = 0, cntb = 0;

    for (let i = 0; i < colors.length; i++) {
        if (colors[i] === 'A') {
            cnta++;
            bob += Math.max(0, cntb - 2);
            cntb = 0;
        } else {
            cntb++;
            alice += Math.max(0, cnta - 2);
            cnta = 0;
        }
    }

    bob += Math.max(0, cntb - 2);
    alice += Math.max(0, cnta - 2);

    return alice > bob;
};
