
function gcd(x, y) {
    while (y !== 0) {
        let temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

function lcm(x, y) {
    return x / gcd(x, y) * y;
}

function isGood(mid, a, b, c, n) {
    let ab = lcm(a, b);
    let ac = lcm(a, c);
    let bc = lcm(b, c);
    let abc = lcm(ab, c);
    let count = Math.floor(mid / a) + Math.floor(mid / b) + Math.floor(mid / c)
              - Math.floor(mid / ab) - Math.floor(mid / ac) - Math.floor(mid / bc)
              + Math.floor(mid / abc);
    return count >= n;
}

/**
 * @param {number} n
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var nthUglyNumber = function(n, a, b, c) {
    let lo = 1, hi = 200000000000000;
    let ans = 1;

    while (lo <= hi) {
        let mid = Math.floor(lo + (hi - lo) / 2);
        if (isGood(mid, a, b, c, n)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
};

