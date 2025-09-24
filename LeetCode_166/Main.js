/**
 * @param {number} numerator
 * @param {number} denominator
 * @return {string}
 */
var fractionToDecimal = function(numerator, denominator) {
    if (numerator == 0) return "0";

    let result = "";

    if ((numerator < 0) ^ (denominator < 0)) {
        result += "-";
    }

    let n = Math.abs(numerator);
    let d = Math.abs(denominator);

    result += Math.floor(n / d);
    let rem = n % d;
    if (rem === 0) return result;

    result += ".";

    const cnt = new Map();
    while (rem) {
        if (cnt[rem]) {
            let index = cnt[rem];
            result = result.slice(0, index) + "(" + result.slice(index) + ")";
            break;
        }

        cnt[rem] = result.length;
        rem *= 10;
        result += Math.floor(rem / d);
        rem %= d;
    }
    return result;
};

console.log(fractionToDecimal(1, 2));
console.log(fractionToDecimal(2, 1));
console.log(fractionToDecimal(4, 333));