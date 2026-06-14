#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        int mx = 0, l = 0, r = nums.size() - 1;

        while (l < r) {
            mx = max(mx, nums[l++] + nums[r--]);
        }
        
        return mx;
    }
};