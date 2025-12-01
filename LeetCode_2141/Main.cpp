#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        auto good = [&](long long T) {
            long long total = 0;
            long long need = T * (long long)n;
            for (int b : batteries) {
                total += min((long long)b, T);
                if (total >= need) return true;
            }
            return total >= need;
        };

        long long sum = 0;
        for (int b : batteries) {
            sum += b;
        }

        long long lo = 0, hi = sum / n;
        long long answer = 0;

        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (good(mid)) {
                answer = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        return answer;
    }
};
