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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy=new ListNode(-1,head),*k=dummy,*pre=dummy;
        if(head==NULL || head->next==NULL)
            return head;
        for(int i=0;i<left;i++){
            pre=k;
            k=k->next;
        }
        ListNode *cur=k ,*prev=pre,*nxt;
        
        for(int i=left;i<=right;i++){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            
        }
        pre->next=prev;
        k->next=cur;
        
        return dummy->next;
        
    }
};