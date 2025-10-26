#include<bits/stdc++.h>
using namespace std;

class Bank {
public:
    vector<long long> val;
    int n;
    Bank(vector<long long>& balance) {
        n = balance.size();
        val.resize(n + 1);
        
        for (int i = 0; i < n; i++) {
            val[i + 1] = balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 <= n && account2 <= n && val[account1] >= money) {
            val[account1] -= money;
            val[account2] += money;
            return true;
        } else {
            return false;
        }
    }
    
    bool deposit(int account, long long money) {
        if (account <= n) {
            val[account] += money;
            return true;
        } else {
            return false;
        }
    }
    
    bool withdraw(int account, long long money) {
        if (account <= n && val[account] >= money) {
            val[account] -= money;
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */