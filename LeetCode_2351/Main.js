/**
 * @param {string} s
 * @return {character}
 */
var repeatedCharacter = function(s) {
    let n = s.length;
    const cnt = {

    }

    for (let i = 0; i < n; i++) {
        if (cnt[s[i]] > 0) {
            return s[i];
        }
        cnt[s[i]] = 1;
    }
    return ' ';
}

const s = "abccbaacz";
console.log(repeatedCharacter(s));