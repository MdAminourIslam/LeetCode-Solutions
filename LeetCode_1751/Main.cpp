#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mem;
    vector<int> next_event;
    int n;
    int dfs(int cur_indx, vector<vector<int>>& events, int k) {
        if (k == 0 || cur_indx >= n) {
            return 0;
        }

        if (mem[cur_indx][k] != -1) {
            return mem[cur_indx][k];
        }

        int skip_event = dfs(cur_indx + 1, events, k);
        int next = next_event[cur_indx];
        int attend_event = dfs(next, events, k - 1) + events[cur_indx][2];
        
        return mem[cur_indx][k] = max(skip_event, attend_event);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(events.begin(), events.end());

        mem.assign(n, vector<int>(k + 1, -1));
        next_event.assign(n, 0);

        for (int i = 0; i < n; i++) {
            next_event[i] = upper_bound(events.begin() + i, events.end(), vector<int>{events[i][1] + 1, 0, 0}) - events.begin();
        }

        return dfs(0, events, k);
    }
};

int main() {
    
    return 0;
}