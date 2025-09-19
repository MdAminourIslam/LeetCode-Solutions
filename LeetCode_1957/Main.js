
/**
 * @param {string} s
 * @return {string}
 */
var makeFancyString = function(s) {
    let res = [];
    for (let i = 0; i < s.length; i++) {
        if (res.length < 2) {
            res.push(s[i]);
        } else {
            let sz = res.length;
            if (res[sz - 1] == res[sz - 2] && res[sz - 1] == s[i]) {
                continue;
            } else {
                res.push(s[i]);
            }
        }
    }
    return res.join('');
};

console.log(makeFancyString("aaabaaaa"));