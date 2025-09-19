/**
 * @param {string} s
 * @param {number} k
 * @param {character} fill
 * @return {string[]}
 */
var divideString = function(s, k, fill) {
    var cur = [];
    const res = [];
    for (let i = 0; i < s.length; i++) {
        cur.push(s[i]);
        if (cur.length == k) {
            res.push(cur.join(''));
            cur = [];
        }
    }
    if (cur.length > 0) {
        while (cur.length < k) {
            cur.push(fill);
        }
        res.push(cur.join(''));
    }
    return res;
};

const s = "abcdefghij", k = 3, fill = "x";
console.log(divideString(s, k, fill));