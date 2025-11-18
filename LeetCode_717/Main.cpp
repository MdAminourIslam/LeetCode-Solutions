#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size() - 1;
        int indx = 0;

        while (indx < n) {
            if (indx + 1 < n) {
                if (bits[indx] == 0)
                    indx += 1;
                else
                    indx += 2;
            } else {
                if (bits[indx] == 1)
                    return false;
                else
                    return true;
            }
                
        }
        return true;
    }
};