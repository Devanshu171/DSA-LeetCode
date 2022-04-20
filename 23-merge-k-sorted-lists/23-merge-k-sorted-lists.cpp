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
     class cmp{
         public:
         bool operator()(ListNode* a,ListNode* b){
             return a->val>b->val;
         }
     };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          
          priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
           int k=lists.size();
           for(int i=0;i<k;i++){
               if(lists[i])
               pq.push(lists[i]);
           }
           ListNode *head=new ListNode(-1),*last=head;
           while(!pq.empty()){
               ListNode *temp=pq.top();
               pq.pop();
               last->next=temp;
               last=temp;
               if(temp->next)
               pq.push(temp->next);
              
           }
           return head->next;
           
    }
};