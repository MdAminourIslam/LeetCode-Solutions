#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidPair(int x1, int y1, int x2, int y2) {
        return x1 <= x2 && y1 >= y2;
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int pairCount = 0;
        int totalPoints = points.size();

        for (int i = 0; i < totalPoints; i++) {
            for (int j = 0; j < totalPoints; j++) {
                if (i == j) continue;

                if (isValidPair(points[i][0], points[i][1], points[j][0], points[j][1])) {
                    int insideCount = 0;

                    for (const auto& point : points) {
                        if (points[i][0] <= point[0] && point[0] <= points[j][0] &&
                            points[j][1] <= point[1] && point[1] <= points[i][1]) {
                            insideCount++;
                        }
                    }

                    if (insideCount < 3) {
                        pairCount++;
                    }
                }
            }
        }
        return pairCount;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1, 3}, {2, 2}, {3, 1}};
    cout << sol.numberOfPairs(points) << endl;
    return 0;
}
