#include <stdbool.h>

bool winnerOfGame(char* colors) {
    int alice = 0, bob = 0;
    int cnta = 0, cntb = 0;

    for (int i = 0; colors[i] != '\0'; i++) {
        if (colors[i] == 'A') {
            cnta++;
            bob += cntb > 2 ? cntb - 2 : 0;
            cntb = 0;
        } else {
            cntb++;
            alice += cnta > 2 ? cnta - 2 : 0;
            cnta = 0;
        }
    }

    bob += cntb > 2 ? cntb - 2 : 0;
    alice += cnta > 2 ? cnta - 2 : 0;

    return alice > bob;
}
