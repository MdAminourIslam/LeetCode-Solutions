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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* answer = nullptr;
        ListNode* answer_head = nullptr;

        while (true) {
            int finished = true;
            int mn_indx = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr) {
                    finished = false;
                    if (mn_indx == -1) {
                        mn_indx = i;
                    } else {
                        if (lists[i]->val < lists[mn_indx]->val) {
                            mn_indx = i;
                        }
                    }
                    
                }
            }

            if (finished) {
                break;
            } else {
                ListNode* newNode = new ListNode(lists[mn_indx]->val);
                lists[mn_indx] = lists[mn_indx]->next;

                if (answer) {
                    answer->next = newNode;
                    answer = answer->next;
                } else {
                    answer = newNode;
                    answer_head = answer;
                }
            }
        }
        return answer_head;
    }
};