#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
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
    vector<vector<int>> intervals = {{1,3}, {2,6},{8,10},{15,18}};

    vector<vector<int>> res = Solution().merge(intervals);

    for (auto it : res) {
        for (int x : it) {
            cout << x << " ";
        }

        cout << "\n";
    }
}