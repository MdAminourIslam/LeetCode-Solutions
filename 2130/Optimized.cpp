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

Twin Pair:
1st node <-> last node
2nd node <-> 2nd last node
3rd node <-> 3rd last node
...

Since a singly linked list does not allow direct access
to the last node, we reverse the second half of the list
so that corresponding twin nodes can be accessed together.

Steps:

1. Find the middle of the linked list using the
   Slow-Fast Pointer technique.
   - slow moves 1 step at a time
   - fast moves 2 steps at a time
   - when the loop ends, slow points to the start
     of the second half

2. Reverse the second half of the list.

   Example:
   5 -> 4 -> 2 -> 1

   slow points to 2

   Reverse:
   2 -> 1

   Becomes:
   1 -> 2

3. Now we have:

   First Half  : 5 -> 4
   Second Half : 1 -> 2

   Traversing both halves simultaneously gives
   the twin pairs automatically:

   5 + 1
   4 + 2

4. Compute and return the maximum twin sum.

Time Complexity : O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* cur = slow;

        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        int answer = 0;

        while (prev) {
            answer = max(answer, head->val + prev->val);

            head = head->next;
            prev = prev->next;
        }

        return answer;
    }
};