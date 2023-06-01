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
    bool isPalindrome(ListNode* head) {
         ListNode *slow = head, *fast = head, *prev, *temp;
        //find middle element
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        
        
        prev = slow, slow = slow->next, prev->next = NULL;
        
        //reverse the list from middle to end
        while (slow)
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;
        
        
        fast = head, slow = prev;
        // now start comparing from start with new reversed list. 
        while (slow)
            if (fast->val != slow->val) return false;
            else fast = fast->next, slow = slow->next;
        return true;
    }
};