/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */

const strToInt = function (s) {
    let num = 0;
    for (let i = 0; i < s.length; i++) {
        num = num * 10 + (parseInt(s[i]));
    }
    return num;
}

const parseVersion = function (s) {
    let version = [];
    let cur = '';
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '.') {
            version.push(strToInt(cur));
            cur = '';
        } else {
            cur += s[i];
        }
    }
    version.push(strToInt(cur));
    return version;
}

var compareVersion = function(version1, version2) {
    
    let v1 = parseVersion(version1);
    let v2 = parseVersion(version2);

    let n = Math.max(v1.length, v2.length);

    for (let i = 0; i < n; i++) {
        let num1 = i < v1.length ? v1[i] : 0;
        let num2 = i < v2.length ? v2[i] : 0;

        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
    }

    return 0;
};

let version1 = "1.2", version2 = "1.10";
console.log(compareVersion(version1, version2));