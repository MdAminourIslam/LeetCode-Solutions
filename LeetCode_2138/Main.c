#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** divideString(char* s, int k, char fill, int* returnSize) {
    int len = strlen(s);
    int groups = (len + k - 1) / k;

    char** res = (char**)malloc(sizeof(char*) * groups);

    for (int i = 0; i < groups; i++) {
        res[i] = (char*)malloc(sizeof(char) * (k + 1));  // +1 for null-terminator

        for (int j = 0; j < k; j++) {
            int indx = (i * k) + j;
            
            res[i][j] = (indx < len ? s[indx] : fill);
        }
        res[i][k] = '\0';
    }
    *returnSize = groups;
    return res;
}

int main() {
    char* s = "abcdefg";
    int k = 3;
    char fill = 'x';
    int returnSize;

    char** res = divideString(s, k, fill, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", res[i]);
        free(res[i]); 
    }
    free(res); 

    return 0;
}
