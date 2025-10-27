/**
 * @param {string[]} bank
 * @return {number}
 */
var numberOfBeams = function(bank) {
    let answer = 0;
    let last = 0;

    for (let s of bank) {
        let cur = 0;
        for (let ch of s) {
            cur += ch == '1';
        }

        if (cur) {
            answer += cur * last;
            last = cur;
        }
    }
    return answer;
};