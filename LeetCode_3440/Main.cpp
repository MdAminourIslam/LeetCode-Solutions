#include<bits/stdc++.h>
using namespace std;

class Solution {
    #define pii pair<int, int>

    int getFreeTimeByRescheduling(int i, vector<pii>& top3Gaps, vector<int>& startTime, vector<int>& endTime) {
        int lastEnd = (i == 0) ? 0 : endTime[i - 1];
        int currentDuration = endTime[i] - startTime[i];

        for (int k = 2; k >= 0; --k) {
            int gapLength = top3Gaps[k].first;
            int gapIndex = top3Gaps[k].second;

            // Ensure we're not using overlapping gaps (i or i+1)
            if (gapLength >= currentDuration && gapIndex != i && gapIndex != i + 1) {
                return startTime[i + 1] - lastEnd;
            }
        }

        // Couldn’t reschedule, deduct current duration
        return (startTime[i + 1] - lastEnd) - currentDuration;
    }

public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        // Add final dummy meeting at eventTime
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);
        int n = startTime.size();

        // Precompute top 3 largest gaps
        vector<pii> top3Gaps(3, {-1, -1});
        top3Gaps[0] = {startTime[0], 0};  // Gap from time 0 to first meeting

        for (int i = 1; i < n; ++i) {
            int gap = startTime[i] - endTime[i - 1];
            pii currentGap = {gap, i};

            if (currentGap.first > top3Gaps[2].first) top3Gaps[2] = currentGap;
            if (top3Gaps[2].first > top3Gaps[1].first) swap(top3Gaps[1], top3Gaps[2]);
            if (top3Gaps[1].first > top3Gaps[0].first) swap(top3Gaps[0], top3Gaps[1]);
        }

        // Try rescheduling each meeting to maximize free time
        int maxFreeTime = 0;
        for (int i = 0; i < n - 1; ++i) {
            int freeTime = getFreeTimeByRescheduling(i, top3Gaps, startTime, endTime);
            maxFreeTime = max(maxFreeTime, freeTime);
        }

        return maxFreeTime;
    }
};
