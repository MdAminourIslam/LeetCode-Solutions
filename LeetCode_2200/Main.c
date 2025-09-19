/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < numsSize; ++j) {
            if (nums[j] == key && abs(i - j) <= k) {
                res[count++] = i;
                break;  
            }
        }
    }
    *returnSize = count;
    return res;
}
