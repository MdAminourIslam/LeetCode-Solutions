#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, num = n, product = 1;
        while (num > 0) {
            sum += num % 10;
            product *= num % 10;
            num /= 10;
        }
        sum += product;
        return n % sum == 0;
    }
};