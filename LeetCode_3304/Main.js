/**
 * @param {number} k
 * @return {character}
 */
var kthCharacter = function(k) {
    let cur = "a";
    while (cur.length < k) {
        let temp = "";
        for (let i = 0; i < cur.length; i++) {
            let d = cur.charCodeAt(i) - 95;
            //JavaScript-এ charCodeAt(i) ফাংশনটি একটি স্ট্রিংয়ের i-তম ক্যারেক্টারের ASCII/Unicode code রিটার্ন করে।
            // a = 95, b = 96....... z = 97
            d = (d + 1) % 26;
            temp += String.fromCharCode(d + '95');
        }
        cur += temp;
    }
    return cur[--k];
};