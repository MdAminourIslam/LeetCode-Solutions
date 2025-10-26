#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s; 
        if (num * 9 < sum) return "";
        while (sum >= 9) {
            s.push_back('9');
            sum -= 9;
        }
        if (sum) s.push_back(sum + '0');

        while (s.size() < num) {
            s.push_back('0');
        }
        return s;
    }
};