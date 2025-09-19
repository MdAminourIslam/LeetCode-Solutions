/**
 * @param {string} word
 * @return {boolean}
 */

function ok(ch) {
    return (ch >= '0' && ch <= '9') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}

function isVowel(ch) {
    return ch === 'a' || ch === 'e' || ch === 'i' || ch === 'o' || ch === 'u' ||
           ch === 'A' || ch === 'E' || ch === 'I' || ch === 'O' || ch === 'U';
}

function isValid(word) {
    if (word.length < 3) return false;

    let vowel = false, consonant = false;

    for (let i = 0; i < word.length; i++) {
        let ch = word[i];

        if (!ok(ch)) return false;

        if (isVowel(ch)) {
            vowel = true;
        } else if (!(ch >= '0' && ch <= '9')) {
            consonant = true;
        }
    }

    return vowel && consonant;
}
