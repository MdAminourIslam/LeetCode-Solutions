#include <stdbool.h>
#include <string.h>

bool ok(char ch) {
    return (ch >= '0' && ch <= '9') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

bool isValid(char* word) {
    int len = 0;
    while (word[len] != '\0') {
        len++;
    }

    if (len < 3) return false;

    bool vowel = false, consonant = false;

    for (int i = 0; i < len; i++) {
        char ch = word[i];

        if (!ok(ch)) return false;

        if (isVowel(ch)) {
            vowel = true;
        } else if (!(ch >= '0' && ch <= '9')) {
            consonant = true;
        }
    }

    return vowel && consonant;
}
