
// Definition for singly-linked list.

function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? undefined : next)
}


/**
 * @param {number[]} nums
 * @param {ListNode} head
 * @return {ListNode}
 */
var modifiedList = function(nums, head) {
    const MAX = 100001;
    const cnt = new Array(MAX).fill(0);

    for (let num of nums) {
        cnt[num] += 1;
    }

    let result = null;
    let resultHead = null;

    while (head) {
        if (!cnt[head.val]) {
            if (resultHead === null) {
                result = head;
                resultHead = head;
            } else {
                result.next = head;
                result = result.next;
            }
        }
        head = head.next;
    }

    result.next = null; // ensure the ending of list
    return resultHead;
};