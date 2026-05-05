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
    int getLength(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;
        int len = getLength(head);
        k %= len;
        if (k == 0) return head;

        ListNode* cur;
        ListNode* originalHead = head;

        for (int i = 1; i <= len - k; i++) {
            cur = head;
            head = head->next;
        }

        ListNode* newPart = cur->next;
        ListNode*answerHead = newPart;

        cur->next = nullptr;

        while (newPart->next != nullptr) {
            newPart = newPart->next;
        }

        newPart->next = originalHead;

        return answerHead;
    }
};
