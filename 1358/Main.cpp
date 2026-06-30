#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& cnt) {
        return cnt[0] and cnt[1] and cnt[2];
    }

    int numberOfSubstrings(string s) {
        vector<int> indx[3];
        int answer = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] - 'a' < 3) {
                indx[s[i] - 'a'].push_back(i);
            }
        }

        for (int i = 0; i < s.size(); i++) {
            auto indx1 = lower_bound(begin(indx[0]), end(indx[0]), i);
            auto indx2 = lower_bound(begin(indx[1]), end(indx[1]), i);
            auto indx3 = lower_bound(begin(indx[2]), end(indx[2]), i);

            if (indx1 == indx[0].end() or indx2 == indx[1].end() or indx3 == indx[2].end()) {
                break;
            }

            int mn = max({*indx1, *indx2, *indx3});
            answer += s.size() - mn;
        }
        return answer;
    }
};