#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lowerSet;
        unordered_set<char> upperSet;
        
        for (char c : word) {
            if (islower(c)) {
                lowerSet.insert(c);
            } else if (isupper(c)) {
                upperSet.insert(tolower(c));
            }
        }
        
        int count = 0;
        for (char c : lowerSet) {
            if (upperSet.count(c)) count++;
        }
        
        return count;
    }
};
