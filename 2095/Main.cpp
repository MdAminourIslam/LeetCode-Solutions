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



/*
Idea:

Use Slow-Fast Pointer to find the middle node.

- slow moves 1 step at a time
- fast moves 2 steps at a time

When the loop ends:
- slow points to the middle node
- prevNode points to the node just before the middle

Delete the middle node by:
    prevNode->next = slow->next;

Special Case:
If the list contains only one node,
the result is an empty list.

Time Complexity : O(n)
Space Complexity: O(1)
*/


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        ListNode*prevNode = nullptr;


        while (fast && fast->next) {
            prevNode = slow;

            slow = slow->next;
            fast = fast->next->next;
        }

        prevNode->next = slow->next;

        return head;
    }
};