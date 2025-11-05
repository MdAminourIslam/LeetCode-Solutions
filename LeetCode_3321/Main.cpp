#include <bits/stdc++.h>
using namespace std;

class Helper {
private:
    int x;
    long long sum;
    unordered_map<int, int> freq;
    set<pair<int, int>> topX, others;

public:
    Helper(int xValue) {
        x = xValue;
        sum = 0;
    }

    void insert(int num) {
        if (freq[num] > 0) removePair({freq[num], num});
        freq[num]++;
        addPair({freq[num], num});
    }

    void remove(int num) {
        removePair({freq[num], num});
        freq[num]--;
        if (freq[num] > 0) addPair({freq[num], num});
    }

    long long getSum() const {
        return sum;
    }

private:
    void addPair(pair<int, int> p) {
        if ((int)topX.size() < x || p > *topX.begin()) {
            sum += 1LL * p.first * p.second;
            topX.insert(p);
            if ((int)topX.size() > x) {
                auto smallest = *topX.begin();
                sum -= 1LL * smallest.first * smallest.second;
                topX.erase(smallest);
                others.insert(smallest);
            }
        } else {
            others.insert(p);
        }
    }

    void removePair(pair<int, int> p) {
        if (!topX.empty() && p >= *topX.begin() && topX.count(p)) {
            sum -= 1LL * p.first * p.second;
            topX.erase(p);
            if (!others.empty()) {
                auto largest = *others.rbegin();
                others.erase(largest);
                topX.insert(largest);
                sum += 1LL * largest.first * largest.second;
            }
        } else {
            others.erase(p);
        }
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> result;
        Helper helper(x);
        for (int i = 0; i < nums.size(); i++) {
            helper.insert(nums[i]);
            if (i >= k) helper.remove(nums[i - k]);
            if (i >= k - 1) result.push_back(helper.getSum());
        }
        return result;
    }
};
