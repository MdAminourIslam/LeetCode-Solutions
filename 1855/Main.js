/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxDistance = function(nums1, nums2) {
    let i = 0, j = 0, ans = 0;

    while (i < nums1.length) {
        while (j < nums2.length && nums2[j] >= nums1[i]) {
            j++;
        }

        if (j >= i + 1) {
            ans = Math.max(ans, j - i - 1);
        }

        i++;
    }

    return ans;
};