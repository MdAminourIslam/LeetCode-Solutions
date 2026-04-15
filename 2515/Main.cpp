#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int answer = -1;

        for (int i = 0; i < n; i++) {
            int right = (startIndex + i) % n;
            int left = ((startIndex - i) + n) % n;

            if (target == words[right]) {
                answer = i;
                break;
            }

            if (target == words[left]) {
                answer = i;
                break;
            }
        }

        return answer;
    }
};