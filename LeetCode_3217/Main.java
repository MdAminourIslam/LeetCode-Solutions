public class Main {

}

//Definition for singly-linked list.

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}


class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        ListNode result = null, resultHead = null;

        boolean[] toRemove = new boolean[100001];
        for (int num : nums) {
            toRemove[num] = true; // Mark values to remove
        }

        while (head != null) {
            if (!toRemove[head.val]) {
                if (resultHead == null) {
                    resultHead = head;
                    result = head;
                } else {
                    result.next = head;
                    result = result.next;
                }
            }
            head = head.next;
        }
        if (result != null) {
            result.next = null;
        }
        return resultHead;
    }
}


