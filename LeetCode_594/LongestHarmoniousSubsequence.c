#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int max(int x, int y) {
    return x > y ? x : y;
}

int findLHS(int* nums, int numsSize) {
    mergeSort(nums, 0, numsSize - 1);
    
    int prev_cnt = 0, cur_cnt = 1, res = 0;
    int prev_num = 0;

    for (int i = 0; i + 1 < numsSize; i++) {
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
}

int main() {
    int n = 8; 
    //scanf("%d", &n);
    int nums [] = {1,3,2,2,5,2,3,7};

    printf("%d\n", findLHS(nums, n));
    return 0;
}
