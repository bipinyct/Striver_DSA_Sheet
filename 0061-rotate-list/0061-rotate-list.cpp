/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode *curr = head;
        int count=1;

        while(curr->next!=NULL){
            curr=curr->next;
            count++;
        }

        curr->next = head;
        curr = head;
        k = k%count;

        for(int i=1; i<(count-k); i++){
            curr = curr->next;
        }
        ListNode *temp = curr->next;
        curr->next = NULL;
        return temp;
    }
};