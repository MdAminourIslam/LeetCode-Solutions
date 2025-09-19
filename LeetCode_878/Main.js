function gcd(x, y) {
    while (y !== 0n) {
        let temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

function lcm(x, y) {
    return x / gcd(x, y) * y;
}

function isGood(mid, a, b, n) {
    let ab = lcm(a, b);
    let count = mid / a + mid / b - mid / ab;
    return count >= n;
}

/**
 * @param {number} n
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var nthMagicalNumber = function(n, a, b) {
    const MOD = 1000000007n;

    // Convert inputs to BigInt
    n = BigInt(n);
    a = BigInt(a);
    b = BigInt(b);

    let lo = 1n, hi = 1000000000000000000n; // 1e18 as BigInt
    let ans = 1n;

    while (lo <= hi) {
        let mid = lo + (hi - lo) / 2n;
        if (isGood(mid, a, b, n)) {
            ans = mid;
            hi = mid - 1n;
        } else {
            lo = mid + 1n;
        }
    }

    return Number(ans % MOD);  // Convert back to Number for final result
};
