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
    ListNode *merge(ListNode *l1,ListNode *l2){
        ListNode *dummy=new ListNode(0);
        ListNode *k=dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val <=l2->val){
                k->next=l1;
                k=l1;
                l1=l1->next;
            }
            else{
                k->next=l2;
                k=l2;
                l2=l2->next;
                
            }
        }
        
        if(l1==NULL)
            k->next=l2;
            if(l2==NULL)
                k->next=l1;
        
        return dummy->next;
        
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *temp,*fast=head,*slow=head;
        
        while(fast!=NULL&& fast->next!=NULL)
        {
            temp=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        temp->next=NULL;
        ListNode *left_side=sortList(head);
        ListNode *right_side=sortList(slow);
        
        return merge(left_side,right_side);
    }
};