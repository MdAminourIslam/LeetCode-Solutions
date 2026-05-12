#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(begin(intervals), end(intervals));

        vector<vector<int>> answer;

        for (auto it : intervals) {
            if (answer.empty()) {
                answer.push_back({it});
            } else {
                if (answer.back().back() >= it[1]) {
                    continue;
                }
                else if (answer.back().back() >= it[0]) {
                    int newl = answer.back()[0];
                    answer.pop_back();
                    answer.push_back({newl, it[1]});
                } else {
                    answer.push_back({it});
                }
            }
        }
        return answer;
    }
};


int main() {
    vector<vector<int>> intervals = {{1,2}, {3,5},{6,7}, {8,10}, {12, 16}};
    vector<int> newInterval = {4,8};
    vector<vector<int>> res = Solution().insert(intervals, newInterval);

    for (auto it : res) {
        for (int x : it) {
            cout << x << " ";
        }

        cout << "\n";
    }
}