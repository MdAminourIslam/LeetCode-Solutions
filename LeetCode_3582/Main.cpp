#include<bits/stdc++.h>
using namespace std;
#define edl '\n'


class Solution {
public:
    string generateTag(string caption) {
        string res;
        res.push_back('#');
        
        caption = "#" + caption;

        for (int i = 1; i < caption.size(); i++) {
            if (caption[i] == ' ') continue;
            
            if (res.size() < 100) {
                if (caption[i - 1] == ' ') {
                    if (res.back() == '#') {
                        res.push_back(tolower(caption[i]));
                    } else {
                        res.push_back(toupper(caption[i]));
                    }
                    
                } else {
                    res.push_back(tolower(caption[i]));
                }
            }
        }
        return res;
    }
};