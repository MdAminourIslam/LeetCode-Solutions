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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* resultHead = nullptr;
        ListNode* current = nullptr;

        while (head) {
            if (head->val != val) {
                if (resultHead ==  nullptr) {
                    resultHead = head;
                    current = head;
                } else {
                    current->next = head;
                    current = current->next;
                }
            }
            head = head->next;
        }

        if (resultHead) {
            current->next = nullptr;
        }

        return resultHead;
    }
};