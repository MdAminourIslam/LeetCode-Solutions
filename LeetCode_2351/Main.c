#include<stdio.h>
#include<string.h>

char repeatedCharacter(char* s) {
    int n = strlen(s);
    int cnt[26] = {0};
    for (int i = 0; i < n; i++) {
        if (cnt[s[i] - 'a']) {
            return s[i];
        }
        cnt[s[i] - 'a']++;
    }
    return ' ';
}