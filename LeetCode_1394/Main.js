/**
 * @param {number[]} arr
 * @return {number}
 */
var findLucky = function(arr) {
    const cnt = [];
    for (let i = 0; i <= 500; i++) {
        cnt[i] = 0;
    }
    for (let i = 0; i < arr.length; i++) {
        cnt[arr[i]]++;
    }

    for (let i = 500; i >= 1; i--) {
        if (cnt[i] == i) {
            return i;
        }
    }
    return -1;
};