#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        // Largest power of 3 in 32-bit signed int range: 3^19 = 1162261467
        return n > 0 && 1162261467 % n == 0;
    }
};