#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int last = log2(n);
        return (1 << (last + 1)) - 1;
    }
};