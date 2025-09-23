/**
 * @param {string} word
 * @return {number}
 */
var numberOfSpecialChars = function(word) {
    const lower = [];
    const upper = [];
    
    for (let i = 0; i < 26; i++) {
        upper[i] = 0;
        lower[i] = 0;
    }

    for (let char of word) {
        const code = char.charCodeAt(0);
        if (code >= 97 && code <= 122) { // a-z
            lower[code - 97] = true;
        } else if (code >= 65 && code <= 90) { // A-Z
            upper[code - 65] = true;
        }
    }
    
    let count = 0;
    for (let i = 0; i < 26; i++) {
        if (lower[i] && upper[i]) count++;
    }
    
    return count;
};
