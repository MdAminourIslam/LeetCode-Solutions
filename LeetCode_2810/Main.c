#include<stdio.h>
#include<string.h>

char* finalString(char* s) {
    int indx = 0, len = 0;
    while (s[indx] != '\0') {
        len += s[indx] == 'i' ? 0 : 1;
        indx += 1;
    }
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    int cur_size = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'i') {
            int l = 0, r = cur_size - 1;

            while (l < r) {
                char ch = res[l];
                res[l] = res[r];
                res[r] = ch;
                l += 1;
                r -= 1;
            }
        } else {
            res[cur_size++] = s[i];
        }
    }
    res[cur_size] = '\0';  //null-terminate the string
    return res;
}