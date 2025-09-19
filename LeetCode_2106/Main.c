int maxTotalFruits(int** fruits, int fruitsSize, int* fruitsColSize, int startPos, int k) {
    const int MX = 200002;
    int* preSum = (int*)calloc(MX, sizeof(int));

    // Fill preSum
    for (int i = 0; i < fruitsSize; i++) {
        int pos = fruits[i][0] + 1; // +1 to avoid 0-index issues
        int amt = fruits[i][1];
        preSum[pos] = amt;
    }

    // Build prefix sum
    for (int i = 1; i < MX; i++) {
        preSum[i] += preSum[i - 1];
    }

    int ans = 0;
    startPos += 1;

    // Move left first, then right
    for (int i = 0; i <= k; i++) {
        int left = startPos - i;
        if (left < 1) left = 1;
        int right = left + (k - i);
        if (right > 200001) right = 200001;
        int sum = preSum[right] - preSum[left - 1];
        if (sum > ans) ans = sum;
    }

    // Move right first, then left
    for (int i = 0; i <= k; i++) {
        int right = startPos + i;
        if (right > 200001) right = 200001;
        int left = right - (k - i);
        if (left < 1) left = 1;
        int sum = preSum[right] - preSum[left - 1];
        if (sum > ans) ans = sum;
    }

    free(preSum);
    return ans;
}
