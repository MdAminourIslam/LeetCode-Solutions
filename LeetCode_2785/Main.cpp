#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        ch = char(tolower(ch));
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
        
    }
    string sortVowels(string s) {
        string vowels;
        for (char ch : s) {
            if (isVowel(ch)) {
                vowels += ch;
            }
        }
       
        sort(begin(vowels), end(vowels));
        string answer;
        int indx = 0;
        
        for (char ch : s) {
            if (isVowel(ch)) {
                answer += vowels[indx++];
            } else {
                answer += ch;
            }
        }
        return answer;
    }
};



