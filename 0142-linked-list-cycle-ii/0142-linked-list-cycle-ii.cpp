/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head, *loop = nullptr;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {loop = fast; break;}
        }
        if (!loop) return loop;
        while (head != loop) {
            head = head->next;
            loop = loop->next;
        }
        return head;
    }
};