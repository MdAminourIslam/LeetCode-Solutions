#include<stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    int cnt[100001] = {0};
    for (int i = 0; i < numsSize; i++) {
        cnt[nums[i]] = 1; 
    }

    struct ListNode* resultHead = NULL;
    struct ListNode* result = NULL;  

    while (head) {
        if (!cnt[head->val]) {  
            if (!resultHead) {
                resultHead = head;
                result = head;
            } else {
                result->next = head;
                result = result->next;
            }
        }
        head = head->next;  
    }

    result->next = NULL;  // Terminate the new list
    return resultHead;
}