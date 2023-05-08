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
    ListNode * helper(ListNode * head){
    if (head == NULL || head->next == NULL)
        return NULL;
    
    ListNode *s  = head;
    ListNode *f  = head;
    ListNode *e = head;
    
    while (f->next && f->next->next) {
        s = s->next;
        f = f->next->next;
        if (s == f) {                      // there is a cycle
            while(s != e) {               // found the e location
                s  = s->next;
                e = e->next;
            }
            return e;
        }
    }
    return NULL; 
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode * s ;
        s = helper(head);
        return s;
    }
};