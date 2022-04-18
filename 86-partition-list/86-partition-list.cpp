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
    ListNode* partition(ListNode* head, int x) {
     
        if(!head || !head->next)
            return head;
        ListNode* less=new ListNode(-1),*more=new ListNode(-1);
        ListNode* last_less=less,*last_more=more;
        ListNode *cur=head;
        while(cur){
            if(cur->val<x){
                last_less->next=cur;
                last_less=cur;
            }else{
                last_more->next=cur;
                last_more=cur;
            }
            cur=cur->next;
        }
        last_less->next=more->next;
        last_more->next=NULL;
        return less->next;
    }
};