/**
 * @param {string} word
 * @return {number}
 */
var possibleStringCount = function(word) {
    let n = word.length;
    let res = 1, cnt = 1;
    for (let i = 0; i + 1 < n; i++) {
        if (word[i] == word[i + 1]) {
            cnt += 1;
        } else {
            res += cnt - 1;
            cnt = 1;
        }
    }
    res += cnt - 1;
    return res;
};