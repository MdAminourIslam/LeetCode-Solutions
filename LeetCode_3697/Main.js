/**
 * @param {number} n
 * @return {number[]}
 */
var decimalRepresentation = function(n) {
    const answer = [];
    let str = n.toString();

    for (let i = 0; i < str.length; i++) {
        if (str[i] > '0') {
            let num = str[i];
            for (let j = i + 1; j < str.length; j++) {
                num += '0';
            }
            answer.push(Number(num));
        }
    }
    return answer;
};

console.log(decimalRepresentation(102));