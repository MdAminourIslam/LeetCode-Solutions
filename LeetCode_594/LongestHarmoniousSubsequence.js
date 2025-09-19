/**
 * @param {number[]} nums
 * @return {number}
 */

function max(x, y) {
    return x > y ? x : y;
}

var findLHS = function(nums) {
    nums.sort((a, b) => a - b);
    let numsSize = nums.length;
    let prev_cnt = 0, cur_cnt = 1, res = 0;
    let prev_num = 0;

    for (let i = 0; i + 1 < numsSize; i++) {
        if (nums[i] == nums[i + 1]) {
            cur_cnt += 1;
        } else {
            if (prev_cnt) {
                if (prev_num + 1 == nums[i]) {
                    res = max(res, prev_cnt + cur_cnt);
                }
            }
            prev_cnt = cur_cnt;
            prev_num = nums[i];
            cur_cnt = 1;
        }
    }

    if (prev_cnt) {
        if (prev_num + 1 == nums[numsSize - 1]) {
            res = max(res, prev_cnt + cur_cnt);
        }
    }
    return res;
};

const nums = [1,3,2,2,5,2,3,7];
console.log(findLHS(nums));