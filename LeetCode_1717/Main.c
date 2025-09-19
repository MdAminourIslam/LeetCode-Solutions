#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int helper(char* s, int x, int y) {
    int cnt_a = 0, cnt_b = 0, ab = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == 'a') {
            cnt_a++;
        } else {
            if (cnt_a > 0) {
                ab++;
                cnt_a--;
            } else {
                cnt_b++;
            }
        }
    }

    int ans1 = ab * x + (cnt_a < cnt_b ? cnt_a : cnt_b) * y;

    cnt_a = cnt_b = 0;
    int ba = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == 'a') {
            if (cnt_b > 0) {
                ba++;
                cnt_b--;
            } else {
                cnt_a++;
            }
        } else {
            cnt_b++;
        }
    }

    int ans2 = ba * y + (cnt_a < cnt_b ? cnt_a : cnt_b) * x;

    return ans1 > ans2 ? ans1 : ans2;
}

int maximumGain(char* s, int x, int y) {
    int ans = 0, n = strlen(s);
    char str[n + 1]; 
    int idx = 0;

    for (int i = 0; ; i++) {
        if (s[i] == '\0' || (s[i] != 'a' && s[i] != 'b')) {
            if (idx > 0) {
                str[idx] = '\0';
                ans += helper(str, x, y);
                idx = 0;
            }
            if (s[i] == '\0') break;
        } else {
            str[idx++] = s[i];
        }
    }

    return ans;
}

int main() {
    char s[1001];
    int x, y;

    printf("Enter the string: ");
    scanf("%s", s);
    printf("Enter x and y: ");
    scanf("%d %d", &x, &y);

    int result = maximumGain(s, x, y);
    printf("Maximum Gain: %d\n", result);

    return 0;
}
