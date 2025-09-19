#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0;
        int cnta = 0, cntb = 0;

        for (char color : colors) {
            if (color == 'A') {
                cnta++;
                bob += max(0, cntb - 2);
                cntb = 0;
            } else {
                cntb++;
                alice += max(0, cnta - 2);
                cnta = 0;
            }
        }

        bob += max(0, cntb - 2);
        alice += max(0, cnta - 2);

        return alice > bob;
    }
};
