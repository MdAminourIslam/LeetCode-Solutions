#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;
        
        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

        result += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return result; 

        result += ".";

        unordered_map<long long, int> mp; // remainder -> position
        while (rem != 0) {
            if (mp.count(rem)) {
                result.insert(mp[rem], "(");
                result += ")";
                break;
            }
            mp[rem] = result.size();
            rem *= 10;
            result += to_string(rem / d);
            rem %= d;
        }
        return result;
    }
};
