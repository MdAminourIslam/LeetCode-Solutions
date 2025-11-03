#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mx = neededTime[0], sum = neededTime[0], answer = 0;
    
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[i - 1]) {
                mx = max(mx, neededTime[i]);
                sum += neededTime[i];
            } else {
                answer += sum - mx;
                sum = mx = neededTime[i];
            }
        }
    
        answer += sum - mx;
        return answer;
    }
};