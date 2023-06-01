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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // naive
        ListNode * head1 = headA;
        ListNode * head2 = headB;
     while(head2 != NULL) {
            ListNode* temp = head1;
            while(temp != NULL) {
              
                if(temp == head2) return head2;
                temp = temp->next;
            }
            head2 = head2->next;
        }

    return NULL;
    }
};