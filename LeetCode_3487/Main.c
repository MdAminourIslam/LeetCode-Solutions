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
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxSum(int* nums, int numsSize) {
    mergeSort(nums, 0, numsSize - 1);
    
    int sum = nums[numsSize - 1];
    int mx = sum;
    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] != nums[i + 1]) {
            sum += nums[i];
            mx = max(mx, sum);
        }
    }
    return mx;
}

int main() {

    return 0;
}


