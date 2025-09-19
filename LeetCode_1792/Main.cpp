#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto calcGain = [&](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (auto &c : classes) {
            maxHeap.push({calcGain(c[0], c[1]), {c[0], c[1]}});
        }

        while (extraStudents--) {
            auto top = maxHeap.top(); maxHeap.pop();
            int pass = top.second.first + 1;
            int total = top.second.second + 1;
            maxHeap.push({calcGain(pass, total), {pass, total}});
        }

        double sum = 0.0;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top(); maxHeap.pop();
            sum += (double)top.second.first / top.second.second;
        }
        return sum / classes.size();
    }
};
