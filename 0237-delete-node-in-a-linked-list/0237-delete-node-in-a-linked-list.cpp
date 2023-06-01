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
    void deleteNode(ListNode* node) {
            node->val = node->next->val;
        node->next = node->next->next;
        
        
//         ListNode * f = node;
//         ListNode * p = node;
//         ListNode *q  = node->next;
        
        
//         while(q!= NULL){
//             p->val = q->val;
//             p=p->next;
//             q=q->next;
//         }
        
//         // cout<<q->val<<endl;
//         cout<<p->val<<endl;
//         // ListNode* nodeTodelete = q;
//         // delete nodeTodelete;
//         p->next = NULL;
//         delete q;
        
        
    }
};