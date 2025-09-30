/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var digitSum = function(s, k) {
    let cur = s;
    
    while (cur.length > k) {
        let newStr = "";
        for (let i = 0; i < cur.length; i += k) {
            let j = Math.min(cur.length, i + k);
            let substr = cur.substring(i, j);

            let sum = 0;
            for (let d of substr) {
                sum += parseInt(d);
            }
            newStr += sum;
        }
        cur = newStr;
    }
    return cur;
};

console.log(digitSum(s = "11111222223", k = 3));
console.log(typeof digitSum(s = "00000000", k = 3));