/**
 * @param {number[]} nums
 * @return {number}
 */
var countHillValley = function(nums) {
    let n = nums.length;
    let cnt = 0;

    for (let i = 1; i < n - 1; i++) {
        if (nums[i] !== nums[i - 1]) {
            let left = nums[i], right = nums[i];

            let indx = i;
            while (indx >= 0) {
                if (nums[indx] !== nums[i]) {
                    left = nums[indx];
                    break;
                }
                indx--;
            }

            indx = i;
            while (indx < n) {
                if (nums[indx] !== nums[i]) {
                    right = nums[indx];
                    break;
                }
                indx++;
            }

            if ((nums[i] > left && nums[i] > right) || (nums[i] < left && nums[i] < right)) {
                //console.log("i = " + i + " and " + nums[i]);
                cnt++;
            }
        }
    }

    return cnt;
};
