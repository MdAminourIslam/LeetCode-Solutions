//Given an object or an array, return if it is empty.

/**
 * @param {Object|Array} obj
 * @return {boolean}
 */

//Approach 1: Using JSON.stringify
var isEmpty = function(obj) {
    return JSON.stringify(obj).length <= 2;
};

//Approach 2: Using Object.keys
var isEmpty = function(obj) {
    return Object.keys(obj).length === 0;
};

//Approach 3: Using loop
var isEmpty = function(obj) {
    for (let x in obj) {
        return false;
    }
    return true;
};