#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        set<int> divisor_seen;
        int num = 1, cnt = 1;

        while (num %k != 0) {
            if (divisor_seen.count(num % k)) {
                return -1;
            }
            divisor_seen.insert(num % k);
            cnt += 1;
            num = ((num * 10) + 1) % k;
        }
        return cnt;
    }
};