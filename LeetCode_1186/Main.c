#include <stdio.h>
#include <limits.h>

int max_element(int* arr, int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx; 
}

int maximumSum(int* arr, int n) {
    int pre_max[n], suf_max[n];
    int cur_sum = 0;
    int mx = max_element(arr, n);

    for (int i = 0; i < n; i++) {
        cur_sum += arr[i];
        if (cur_sum < 0) {
            cur_sum = 0;
        } else {
            if (cur_sum > mx) mx = cur_sum;
        }
        pre_max[i] = cur_sum;
    }

    cur_sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur_sum += arr[i];
        if (cur_sum < 0) {
            cur_sum = 0;
        }
        suf_max[i] = cur_sum;
    }

    for (int i = 1; i + 1 < n; i++) {
        int sum = (pre_max[i - 1] + suf_max[i + 1] > 0 ? pre_max[i - 1] + suf_max[i + 1] : -1000000000);
        if (sum > mx) mx = sum;
    }

    return mx;
}
