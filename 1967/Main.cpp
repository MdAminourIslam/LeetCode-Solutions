#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int answer = 0;
        for (string s : patterns) {
            int n = s.size();

            for (int i = 0; i + n <= word.size(); i++) {
                if (s == word.substr(i, n)) {
                    answer += 1;
                    break;
                }
            }
        }
        return answer;
    }
};