
int max(int a, int b) {
    return a > b ? a : b;
}

int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    int n = startTimeSize;
        
    int pre[n + 1];
    for (int i = 0, cur = 0; i < n; i++) {
        cur += endTime[i] - startTime[i];
        pre[i] = cur;
    }
    int res = 0;
    for (int i = k - 1; i < n; i++) {
        int left = i + 1 == k ? 0 : endTime[i - k];
        int right = i + 1 == n ? eventTime : startTime[i + 1];
        int sum = i + 1 == k ? pre[i] : pre[i] - pre[i - k];
        res = max(res, right - left - sum);
    }
    return res;
}