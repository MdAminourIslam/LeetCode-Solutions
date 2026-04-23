#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int, vector<int>> indxes;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            indxes[nums[i]].push_back(i);
        }

        vector<long long> answer(n, 0);

        for (auto it : indxes) {
            int num = it.first;

            if (indxes[num].size() > 1) {
                vector<long long> suff(indxes[num].size() + 1, 0);

                for (int i = indxes[num].size() - 1; i >= 0; i--) {
                    suff[i] = suff[i + 1] + indxes[num][i];
                }

                int cur = 0;
                for (int i = 0; i < indxes[num].size(); i++) {
                    long long res = 0;

                    if (i > 0) {
                        res += (1LL * i * indxes[num][i]) - cur;
                    }

                    if (i + 1 < indxes[num].size()) {
                        res += (suff[i + 1]) - (1LL * (indxes[num].size() - i - 1) * indxes[num][i]);
                    }

                    answer[indxes[num][i]] = res;
                    cur += indxes[num][i];
                }
            }
        }
        return answer;
    }
};