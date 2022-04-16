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
    ListNode* reverse(ListNode * begin,ListNode *end){
        ListNode *cur=begin->next,*first=cur,*prev=NULL;
        while(cur!=end){
            ListNode* nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        begin->next=prev;
        first->next=cur;
        return first;        
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k==1)
            return head;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *begin=dummy;
        int i=0;
        while(head){
            i++;
            if(i%k==0){
                begin=reverse(begin,head->next);
                head=begin->next;
            }else{
                head=head->next;
            }
        }
        return dummy->next;
    }
};