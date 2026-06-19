#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0, sum = 0;
        for (int x : gain) {
            sum += x;
            mx = max(mx, sum);
        }
        return mx;
    }
};