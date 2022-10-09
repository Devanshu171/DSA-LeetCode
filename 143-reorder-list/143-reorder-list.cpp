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
    void reorderList(ListNode* head) {
        if(!head) return;
       deque<ListNode*>dq;
        ListNode *k=head;
        while(k){
            dq.push_back(k);
            k=k->next;
        }
        while(dq.size()>1){
            ListNode *f=dq.front();
            dq.pop_front();
            ListNode *e=dq.back();
            dq.pop_back();
            cout<<f->val<<" "<<e->val<<endl;
            e->next=f->next;
            f->next=e;
        }
        
        dq.front()->next=NULL;
    }
};