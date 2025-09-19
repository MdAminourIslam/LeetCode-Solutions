/**
 * @param {string} s
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var helper = function(s, x, y) {
    let cnt_a = 0;
    let cnt_b = 0;
    let ab = 0;
    for (let ch of s) {
        if (ch == 'a') {
            cnt_a += 1;
        } else {
            if (cnt_a) {
                ab += 1;
                cnt_a -= 1;
            } else {
                cnt_b += 1;
            }
        }
    }
    let ans1 = (ab * x) + Math.min(cnt_a, cnt_b) * y;
    cnt_a = cnt_b = 0;
    let ba = 0;
    for (let ch of s) {
        if (ch == 'a') {
            if (cnt_b) {
                ba += 1;
                cnt_b -= 1;
            } else {
                cnt_a += 1;
            }
        } else {
            cnt_b += 1;
        }
    }
    let ans2 = (ba * y) + Math.min(cnt_a, cnt_b) * x;
    return Math.max(ans1, ans2);
}

var maximumGain = function(s, x, y) {
    const str = [];
    let cur = "";
    
    for (let ch of s) {
        if (ch == 'a' || ch == 'b') {
            cur += ch;
        } else {
            str.push(cur);
            cur = "";
        }
    }
    if (cur.length > 0) {
        str.push(cur);
    }
    let ans = 0;
    for (const ss of str) {
        ans += helper(ss, x, y);
    }
    return ans;
};

const s = "aabbaaxybbaabb", x = 5, y = 4;

console.log(maximumGain(s, x, y));