#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>> row(n + 1), col(n + 1);

        for (auto &v : buildings) {
            int x = v[0];
            int y = v[1];
            row[y].push_back(x);
            col[x].push_back(y);
        }

        for (int i = 1; i <= n; i++) {
            sort(row[i].begin(), row[i].end());
            sort(col[i].begin(), col[i].end());
        }

        int answer = 0;

        for (auto &v : buildings) {
            int x = v[0];
            int y = v[1];

            auto &r = row[y];
            auto &c = col[x];

            int posR = lower_bound(r.begin(), r.end(), x) - r.begin();
            int posC = lower_bound(c.begin(), c.end(), y) - c.begin();

            bool left  = (posR > 0);
            bool right = (posR + 1 < r.size());
            bool down  = (posC > 0);
            bool up    = (posC + 1 < c.size());

            if (left && right && down && up)
                answer++;
        }

        return answer;
    }
};
