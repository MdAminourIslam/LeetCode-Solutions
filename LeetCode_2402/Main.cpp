#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n, 0);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used;
        priority_queue<int, vector<int>, greater<int>> free;
        
        for (int i = 0; i < n; i++) {
            free.push(i);
        }

        sort(meetings.begin(), meetings.end());

        for (auto meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            while (!used.empty() && used.top().first <= start) {
                int room = used.top().second;
                used.pop();
                free.push(room);
            }
            if (!free.empty()) {
                int room = free.top();
                free.pop();
                used.push({end, room});
                cnt[room]++;
            } else {
                auto [roomAvailabilityTime, room] = used.top();
                used.pop();
                used.push({roomAvailabilityTime + end - start, room});
                cnt[room]++;
            }
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        for (int i = 0; i < n; i++) {
            if (cnt[i] == mx) {
                return i;
            }
        }
        return -1;
    }
};




/*

*/