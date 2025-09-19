int possibleStringCount(char* word) {
    int n = strlen(word);
    int res = 1, cnt = 1;
    for (int i = 0; i + 1 < n; i++) {
        if (word[i] == word[i + 1]) {
            cnt += 1;
        } else {
            res += cnt - 1;
            cnt = 1;
        }
    }
    res += cnt - 1;
    return res;
}