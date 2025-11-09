#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countOperations(int num1, int num2) {
        int opreation = 0;

        while (num1 and num2) {
            if (num1 < num2) swap(num1, num2);

            opreation += num1 / num2;
            num1 %= num2;
        }
        return opreation;
    }
};