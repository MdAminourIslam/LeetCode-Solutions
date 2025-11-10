#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& a) {
        int op = 0;
        for(int i = 1; i < a.size(); i++) {
            if(a[i] <= a[i - 1]) {
                op += a[i - 1] - a[i] + 1;
                a[i] = a[i - 1] + 1;
            } 
            
        }
        return op;
    }
};