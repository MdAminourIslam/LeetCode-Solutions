#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 && carry > 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry == 1) {
            vector<int> result(digits.size() + 1);
            result[0] = 1;
            for (int i = 0; i < digits.size(); i++) {
                result[i + 1] = digits[i];
            }
            return result;
        }
        return digits;
    }
};