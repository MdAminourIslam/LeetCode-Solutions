#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        long long total = 0;
        for (int x : nums) total = (total + x) % p;

        if (total == 0) return 0;

        map<int, vector<int>> modIndex;
        modIndex[0].push_back(n);
        long long suffix = 0;

        for (int i = n - 1; i >= 0; i--) {
            suffix = (suffix + nums[i]) % p;
            modIndex[suffix].push_back(i);
        }

        for (auto &it : modIndex) {
            sort(it.second.begin(), it.second.end());
        }

        int answer = n;

        long long prefix = 0;

        for (int i = 0; i < n; i++) {

            prefix = (prefix + nums[i]) % p;

            long long need = (p - prefix) % p;

            if (!modIndex.count(need)) continue;

            auto &v = modIndex[need];

            int pos = upper_bound(v.begin(), v.end(), i) - v.begin();

            if (pos < v.size()) {
                int j = v[pos];
                int len = j - i - 1;
                answer = min(answer, len);
            }
        }
        auto &v = modIndex[0];
        int pos = upper_bound(v.begin(), v.end(), -1) - v.begin();
        int j = v[pos];
        int len = j - (-1) - 1;
        answer = min(answer, len);
        return answer == n ? -1 : answer;
    }
};
