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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newNode = new ListNode(head->val);
        ListNode* res_head = newNode;
        ListNode* res = newNode;
        while (head != nullptr) {
            if (head->val != res->val) {
                ListNode* newNode = new ListNode(head->val);
                res->next = newNode;
                res = res->next;
            }
            head = head->next;
        }
        return res_head;
    }
};