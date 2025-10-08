const good = (spell, potions, success) => {
    let ans = potions.length;
    let lo = 0, hi = potions.length - 1;

    while (lo <= hi) {
        let mid = Math.floor((lo + hi) / 2);

        if (spell * potions[mid] >= success) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
};

/**
 * @param {number[]} spells
 * @param {number[]} potions
 * @param {number} success
 * @return {number[]}
 */
var successfulPairs = function(spells, potions, success) {
    potions.sort((a, b) => a - b);

    const answer = [];
    let n = potions.length;
    for (let spell of spells) {
        answer.push(n - good(spell, potions, success));
    }
    return answer;
};

let spells = [5,1,3], potions = [1,2,3,4,5], success = 7;
console.log(successfulPairs(spells, potions, success));

spells = [3,1,2], potions = [8,5,8], success = 16;
console.log(successfulPairs(spells, potions, success));