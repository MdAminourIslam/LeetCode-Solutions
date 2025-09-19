/**
 * @param {number[]} fruits
 * @return {number}
 */
var totalFruit = function(fruits) {
    let cnt = new Map();
    let ans = 1;
    for (let i = 0, j = 0; i < fruits.length; i++) {
        cnt.set(fruits[i], (cnt.get(fruits[i]) || 0) + 1);
        while (cnt.size() > 2) {
            cnt.set(fruits[j], cnt.get(fruits[j]) - 1);
            if (cnt.get(fruits[j]) === 0) {
                cnt.delete(fruits[j]);
            }
            j++;
        }
        ans = Math.max(ans, i - j + 1);
    }
    return ans;
};

console.log(undefined) // undefined
console.log(undefined || 0) // 0