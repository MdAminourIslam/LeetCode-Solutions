/**
 * @param {number} eventTime
 * @param {number} k
 * @param {number[]} startTime
 * @param {number[]} endTime
 * @return {number}
 */
var maxFreeTime = function(eventTime, k, startTime, endTime) {
    let n = startTime.length;
        
    let pre = [];
    for (let i = 0, cur = 0; i < n; i++) {
        cur += endTime[i] - startTime[i];
        pre[i] = cur;
    }
    let res = 0;
    for (let i = k - 1; i < n; i++) {
        let left = i + 1 == k ? 0 : endTime[i - k];
        let right = i + 1 == n ? eventTime : startTime[i + 1];
        let sum = i + 1 == k ? pre[i] : pre[i] - pre[i - k];
        res = Math.max(res, right - left - sum);
    }
    return res;
};