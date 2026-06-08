#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* answer = new ListNode(0);
        ListNode* answer_head = answer;

        ListNode* temp = head;

        while (head) {
            if (head->val < x) {
                answer->next = new ListNode(head->val);
                answer = answer->next;
            }
            head = head->next;
        }

        while (temp) {
            if (temp->val >= x) {
                answer->next = new ListNode(temp->val);
                answer = answer->next;
            }
            temp = temp->next;
        }

        return answer_head->next;
    }
};