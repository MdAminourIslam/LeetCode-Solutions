/**
 * @param {number[]} nums
 * @return {number}
 */
var countValidSelections = function(nums) {
    const ok = (cur, direction) => {
        const temp = nums.slice();
        const n = temp.length;
        while (cur >= 0 && cur < n) {
            if (temp[cur] === 0) {
                cur += direction;
            } else {
                temp[cur] -= 1;
                direction *= -1;
                cur += direction;
            }
        }
        for (let i = 0; i < temp.length; i++) {
            if (temp[i] !== 0) return false;
        }
        return true;
    };

    let answer = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === 0) {
            if (ok(i, 1)) answer++;
            if (ok(i, -1)) answer++;
        }
    }
    return answer;
};

