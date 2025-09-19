#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int op = 0;
        for (int i = shifts.size() - 1; i >= 0; i--) {
            op += shifts[i];
            int d = s[i] - 'a';
            d = (d + op) % 26;
            s[i] = d + 'a';
        }
        return s;
    }
};

signed main() {

    return 0;
}