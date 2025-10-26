#include<bits/stdc++.h>
using namespace std;

class ATM {
public:
    vector<int> banknotes;
    ATM() {
        banknotes.assign(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            banknotes[i] += banknotesCount[i];
        }
    }
    
    int findNotes(int i) {
        if (i == 4) return 500;
        if (i == 3) return 200;
        if (i == 2) return 100;
        if (i == 1) return 50;
        if (i == 0) return 20;
        return 0;
    }

    vector<int> withdraw(int amount) {
        vector<int> resultNotes(5, 0);
        int remaining = amount;

        for (int i = 4; i >= 0; i--) {
            int notes = findNotes(i);
            int take = min(banknotes[i], remaining / notes);
            resultNotes[i] = take;
            remaining -= take * notes;
        }

        if (remaining != 0) return vector<int>{-1};

        for (int i = 0; i < 5; i++) banknotes[i] -= resultNotes[i];
        return resultNotes;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */