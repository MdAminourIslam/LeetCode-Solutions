
int findLucky(int* arr, int arrSize) {
    int cnt[501] = {0};
    
    for (int i = 0; i < arrSize; i++) {
        cnt[arr[i]]++;
    }

    for (int i = 500; i >= 1; i--) {
        if (cnt[i] == i) {
            return i;
        }
    }
    return -1;
}