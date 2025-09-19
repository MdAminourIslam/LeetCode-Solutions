#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    char kthCharacter(int k) {
        string cur = "a";
        while (cur.size() < k) {
            string temp = cur;
            for (int i = 0; i < cur.size(); i++) {
                int d = cur[i] - 'a';
                d = (d + 1) % 26;
                temp[i] = d + 'a';
            }
            cur += temp;
        }
        return cur[k - 1];
    }
};

int main() {

    return 0;
}
