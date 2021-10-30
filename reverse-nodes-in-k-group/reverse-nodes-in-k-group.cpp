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
    int Length(ListNode *k){
        int count=0;
        while(k!=NULL){
            count++;
            k=k->next;
        }
        return count;
    }
    ListNode *reverseInGroup(ListNode *head,int k,int len){
        if(k>len)
            return head;
        ListNode *cur=head,*prev=NULL,*nxt;
        int count=0;
        
        while(cur!=NULL && count<k){
            count++;
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        
        if(nxt!=NULL)
            head->next=reverseInGroup(nxt,k,len-k);
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=Length(head);
        return reverseInGroup(head,k,len);
    }
};