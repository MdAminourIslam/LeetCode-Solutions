var shiftingLetters = function(s, shifts) {
    let op = 0;
    let arr = s.split('');
    for (let i = shifts.length - 1; i >= 0; i--) {
        op += shifts[i];
        let d = arr[i].charCodeAt(0) - 'a'.charCodeAt(0);
        d = (d + op) % 26;
        arr[i] = String.fromCharCode(d + 'a'.charCodeAt(0));
    }
    return arr.join('');
};
