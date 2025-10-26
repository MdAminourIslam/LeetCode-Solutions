#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexSmallest(string s) {
        string result(s.size(), 'z');

        for (int i = 0; i < s.size(); i++) {
            string a = s.substr(0, i);
            reverse(begin(a), end(a));
            a += s.substr(i);
            result = min(result, a);
        }

        for (int i = 0; i < s.size(); i++) {
            string a = s.substr(i);

            reverse(begin(a), end(a));
            a = s.substr(0, i) + a;
            result = min(result, a);
        }
        return result;
    }
};