/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    const result = [];
    for (let i = 0; i < arr.length; i += size) {
        let j = Math.min(i + size, arr.length);
        let subArray = [];
        for (let k = i; k < j; k++) {
            subArray.push(arr[k]);
        }
        result.push(subArray);
    }
    return result;
};


console.log(chunk([1,9,6,3,2], 3));