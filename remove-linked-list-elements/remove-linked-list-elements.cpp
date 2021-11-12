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
    ListNode* removeElements(ListNode* head, int v) {
        ListNode *dummy=new ListNode(-1,head);
        ListNode *t=dummy;
        while(t->next){
            while(t->next && t->next->val==v){
                ListNode *del=t->next;
                t->next=del->next;
                delete del;
            }
            if(t->next!=NULL)
            t=t->next;
            }
        return dummy->next;
        }
    
};