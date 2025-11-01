#include<bits/stdc++.h>
using namespace std;



// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* result = nullptr;
        ListNode* resultHead = nullptr;

        map<int, int> cnt;
        for (int x : nums) {
            cnt[x] += 1;
        }

        while (head) {
            if (!cnt[head->val]) {
                if (resultHead == nullptr) {
                    resultHead = head;
                    result = head;
                } else {
                    result->next = head;
                    result = result->next;
                }
            }
            head = head->next;
        }
        result->next = nullptr;
        return resultHead;
    }
};