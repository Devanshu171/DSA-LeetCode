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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL)
            return head;
        
        ListNode *dummy=new ListNode(-1,head);
        ListNode *fast=dummy,*slow=dummy,*cur;
        
        for(int i=0;i<k;i++){
            fast=fast->next;
            cur=fast;
        }
        
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
      
        
        swap(cur->val,slow->val);
        return dummy->next;
    }
};