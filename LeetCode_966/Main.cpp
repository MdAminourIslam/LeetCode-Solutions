#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = wordlist.size();
        map<string, int> equal, cap, vow;

        for (int i = n - 1; i >= 0; i--) {
            equal[wordlist[i]] = i + 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            string word = wordlist[i];
            transform(word.begin(), word.end(), word.begin(), ::toupper);
            cap[word] = i + 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            string word;
            for (char ch : wordlist[i]) {
                if (isVowel(ch)) {
                    word += 'a';
                } else {
                    word += char(toupper(ch));
                }
            }
            vow[word] = i + 1;
        }

        vector<string> answer;
        for (string query : queries) {
            string word = query;
            transform(word.begin(), word.end(), word.begin(), ::toupper);
            string word2;
            for (char ch : query) {
                if (isVowel(ch)) {
                    word2 += 'a';
                } else {
                    word2 += char(toupper(ch));
                }
            }

            if (equal[query]) {
                answer.push_back(wordlist[equal[query] - 1]);
            } else if (cap[word]) {
                answer.push_back(wordlist[cap[word] - 1]);
            } else if (vow[word2]) {
                answer.push_back(wordlist[vow[word2] - 1]);
            } else {
                answer.push_back("");
            }
        }

        return answer;

    }
};

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}