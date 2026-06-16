#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string answer;

        for (char ch : s) {
            if(ch >= 'a'&& ch <= 'z') {
                answer.push_back(ch);
            } else if (ch == '*') {
                if (answer.size()) {
                    answer.pop_back();
                }
            } else if (ch == '#') {
                answer += answer;
            } else {
                reverse(begin(answer ), end(answer));
            }
        }
        return answer;
    }
};