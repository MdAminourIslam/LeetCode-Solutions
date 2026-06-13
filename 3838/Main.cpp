#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        map<int, char> cnt;
        int i = 25;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            cnt[i--] = ch;
        }

        string answer;

        for (string word : words) {
            int sum = 0;
            for (char ch : word) {
                sum += weights[ch - 'a'];
            }
            answer.push_back(cnt[sum % 26]);
        }
        return answer;
    }
};