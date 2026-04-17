#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNumber(int n) {
        int revNum = 0;

        while (n > 0) {
            revNum = (revNum * 10) + (n % 10);
            n /= 10;
        }

        return revNum;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        map<int, int> indx;

        int n = nums.size();
        int answer = n;

        for (int i = 0; i < n; i++) {

            if (indx[nums[i]]) {
                answer = min(answer, i - indx[nums[i]] + 1);
            }
            indx[reverseNumber(nums[i])] = i + 1;
        }

        return answer == n ? -1 : answer;
    }
};