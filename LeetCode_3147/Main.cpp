#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int answer = INT_MIN;

        for (int i = n - 1; i >= n - k; i--) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += energy[j];
                answer = max(answer, sum);
            }
        }
        return answer;
    }
};