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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *prev=head,*nxt=head->next;
        while(nxt!=NULL){
            
            if(prev->val==nxt->val){
                prev->next=nxt->next;
                delete nxt;
                nxt=prev->next;
            }
            else{
                prev=nxt;
                nxt=nxt->next;
            }
        }
    
        return head;
    }
};