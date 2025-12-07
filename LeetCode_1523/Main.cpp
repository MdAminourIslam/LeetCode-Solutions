#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(int n) {
        return (n + 1) / 2;
    }
    int countOdds(int low, int high) {
        return func(high) - func(low - 1);
    }
};