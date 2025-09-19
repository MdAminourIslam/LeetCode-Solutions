#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int indx = 0, res = 0;
        for (int x : players) {
            int lo = lower_bound(trainers.begin() + indx, trainers.end(), x) - trainers.begin();
            if (lo == trainers.size()) {
                break;
            }
            res += 1;
            indx = lo + 1;
        }
        return res;
    }
};