#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;

        for (int i = 0; i < 32; i++) {
            if ( ((1 << i) & x) != ((1 << i) & y) ) {
                cnt++;
            }
        }

        return cnt;
    }
};
