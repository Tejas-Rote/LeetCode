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
    ListNode* middleNode(ListNode* head) {
        int n =0;
        ListNode* t = head;
        while(t!= NULL){
            t = t->next;
            n++;
        }
        
        // cout<<n<<endl;
        int middle = n/2;
        ListNode* ans = head;
        for(int i=0;i<middle;i++){
            ans = ans->next;
        }
        return ans;
    }
};