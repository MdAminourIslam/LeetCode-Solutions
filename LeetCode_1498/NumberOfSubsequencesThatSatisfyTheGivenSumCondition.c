#include<stdio.h>

const int mod = 1e9 + 7;

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

void preCompute(int* power_of_two, int n) {
    power_of_two[0] = 1;
    for (int i = 1; i < n; i++) {
        power_of_two[i] = (power_of_two[i - 1] * 2) % mod;
    }
}

int max(int x, int y) {
    return x > y ? x : y;
}

int numSubseq(int* nums, int numsSize, int target) {
    mergeSort(nums, 0, numsSize - 1);

    int power_of_two[numsSize];
    preCompute(power_of_two, numsSize);
    int l = 0, r = numsSize - 1;
    int subSequence = 0;
    
    while (l <= r) {
        if (nums[l] + nums[r] > target) {
            r -= 1;
        } else {
            subSequence += power_of_two[r - l];
            subSequence %= mod;
            l += 1;
        }
    }
    return subSequence;
}

int main() {
    int numsSize = 4;
    int nums[] = {3,5,6,7}, target = 9;
    printf("%d", numSubseq(nums, numsSize, target));
}