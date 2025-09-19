#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> convertBinary(unsigned int num) {
        vector<int> bits(32, 0);
        for (int i = 0; i < 32; i++) {
            if (num & (1U << i)) {
                bits[i] = 1;
            } 
        }
        return bits;
    }

    vector<int> compliment(unsigned int num) {
        vector<int> bits(32, 1);
        for (int i = 0; i < 32; i++) {
            if (num & (1U << i)) {
                bits[i] = 0;
            } 
        }
        int carry = 1;
        for (int i = 0; i < 32; i++) {
            int sum = bits[i] + carry;
            bits[i] = sum % 2;
            carry = sum / 2;
        }
        return bits;
    }

    char helper(int num) {
        if (num < 10) {
            return num + '0';
        } else if (num == 10) {
            return 'a';
        } else if (num == 11) {
            return 'b';
        } else if (num == 12) {
            return 'c';
        } else if (num == 13) {
            return 'd';
        } else if (num == 14) {
            return 'e';
        } else {
            return 'f';
        }
    }

    string toHex(int num) {
        if (num == 0) return "0";

        vector<int> bits;
        if (num < 0) {
            unsigned int n = static_cast<unsigned int>(-num);
            bits = compliment(n); // ✅ use custom 2's complement
        } else {
            bits = convertBinary(static_cast<unsigned int>(num));
        }

        string ans;
        for (int i = 0; i < 32; i += 4) {
            int x = (1 * bits[i]) + (2 * bits[i + 1]) + (4 * bits[i + 2]) + (8 * bits[i + 3]);
            ans += helper(x);
        }

        // Remove leading zeros from the right side
        while (!ans.empty() && ans.back() == '0') {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
