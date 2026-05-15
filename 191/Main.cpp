#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                result += 1;
            }
        }
        return result;
    }
};