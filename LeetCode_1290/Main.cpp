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
    int getDecimalValue(ListNode* head) {
        vector<int> a;
        
        while (head->next) {
            a.push_back(head->val);
            head = head->next;
        }

        reverse(begin(a), end(a));

        int binary = 0;
        for (int i = 0; i < a.size(); i++) {
            binary += (1 << i) * a[i];
        }
        return binary;
    }
};