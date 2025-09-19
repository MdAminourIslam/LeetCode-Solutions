#include<stdio.h>
#include<string.h>


char* makeFancyString(char* s) {
    int n = strlen(s);

    char* res = (char*)malloc((n + 1 ) * sizeof(char));
    int res_indx = 0;
    for (int i = 0; i < n; i++) {
        if (res_indx < 2) {
            res[res_indx++] = s[i];
        } else {
            int sz = res_indx;
            if (res[sz - 1] == res[sz - 2] && res[sz - 1] == s[i]) {
                continue;
            } else {
                res[res_indx++] = s[i];
            }
        }
    }
    res[res_indx] = '\0';
    return res;
}