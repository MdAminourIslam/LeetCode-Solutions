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
Use slow & fast pointer.

- slow moves 1 step
- fast moves 2 steps

When fast reaches end,
slow will be at the middle node.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};