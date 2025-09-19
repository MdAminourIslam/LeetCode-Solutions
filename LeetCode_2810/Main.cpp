#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(string &s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            char ch = s[l];
            s[l] = s[r];
            s[r] = ch;
            l += 1;
            r -= 1;
        }
    }

    string finalString(string s) {
        string res;
        for (char ch : s) {
            if (ch == 'i') {
                reverse(res);
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
};

int main() {
    
}