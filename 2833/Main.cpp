#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int mn = 0, mx = 0;

        for (char ch : moves) {
            if (ch == 'L') {
                mn -= 1;
                mx -= 1;
            } else if (ch == 'R') {
                mn += 1;
                mx += 1;
            } else {
                mn -= 1;
                mx += 1;
            }
        }

        return max(abs(mn), abs(mx));
    }
};