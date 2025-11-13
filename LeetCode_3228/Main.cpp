#include<bits/stdc++.h>
using namespace std;
#define edl '\n'

class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, operation = 0;

        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] == '0' && s[i + 1] == '1') {
                operation += ones;
            }
            ones += s[i] == '1';
        }

        if (s.back() == '0') {
            operation += ones;
        }
        return operation;
    }
};