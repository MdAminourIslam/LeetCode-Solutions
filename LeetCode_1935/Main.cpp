#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(string& word, unordered_set<char>& broken) {
        for (char c : word) {
            if (broken.count(c)) return false;
        }
        return true;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int answer = 0;
        string word = "";

        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                if (!word.empty() && helper(word, broken)) {
                    answer++;
                }
                word = "";
            } else {
                word += text[i];
            }
        }

        if (!word.empty() && helper(word, broken)) {
            answer++;
        }

        return answer;
    }
};

int main() {
    cout << true + true;
    return 0;
}
