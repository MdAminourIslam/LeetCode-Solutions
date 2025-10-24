#include<bits/stdc++.h>
using namespace std;


//Approach 1: Enumeration
/*

*/
class Solution {
public:
    bool isBalance(int x) {
        vector<int> count(10);
        while (x > 0) {
            count[x % 10]++;
            x /= 10;
        }
        for (int d = 0; d < 10; ++d) {
            if (count[d] > 0 && count[d] != d) {
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; ++i) {
            if (isBalance(i)) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    int n = 1;
    int ans = s.nextBeautifulNumber(n);
    cout << "Next beautiful number after " << n << " is: " << ans << endl;
    return 0;
}