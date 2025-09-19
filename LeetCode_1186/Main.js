/**
 * @param {number[]} arr
 * @return {number}
 */
var maximumSum = function(arr) {
    const n = arr.length;
    const pre_max = new Array(n).fill(0);
    const suf_max = new Array(n).fill(0);
    let cur_sum = 0;
    let mx = Math.max(...arr);

    for (let i = 0; i < n; i++) {
        cur_sum += arr[i];
        if (cur_sum < 0) {
            cur_sum = 0;
        } else {
            mx = Math.max(mx, cur_sum);
        }
        pre_max[i] = cur_sum;
    }

    cur_sum = 0;
    for (let i = n - 1; i >= 0; i--) {
        cur_sum += arr[i];
        if (cur_sum < 0) {
            cur_sum = 0;
        }
        suf_max[i] = cur_sum;
    }

    for (let i = 1; i + 1 < n; i++) {
        let sum = (pre_max[i - 1] + suf_max[i + 1] > 0 ? pre_max[i - 1] + suf_max[i + 1] : -1000000000);
        mx = Math.max(mx, sum);
    }

    return mx;
};
