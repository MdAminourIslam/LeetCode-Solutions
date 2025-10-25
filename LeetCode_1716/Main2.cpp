#include<bits/stdc++.h>
using namespace std;

//Approach 2: Math

class Solution {
public:
    int sumOfFirstN(int num) {
        return num * (num + 1) / 2;
    }
    int seriesSum(int strt, int dif, int n) {
        return (((2 * strt) + ((n - 1) * dif)) * n) / 2;
    }
    int totalMoney(int n) {
        if (n <= 7) {
            return sumOfFirstN(n);
        }

        int result = seriesSum(sumOfFirstN(7), 7, n / 7);
        
        if (n % 7) {
            int strt = (n / 7) + 1;
            int rem = n % 7;

            result += sumOfFirstN(strt + rem) - sumOfFirstN(strt - 1);
        }
        return result;
    }
};

