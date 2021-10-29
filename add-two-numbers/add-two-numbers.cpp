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
    ListNode *P=NULL,*last=NULL;
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
            return NULL;
        int c=0;
        while(c || l1 || l2){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
              
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
          
           
            sum+=c;
            c=0;
            int dig=sum%10;
            c=sum/10;
            
                ListNode *temp=new ListNode(dig);
            temp->next=NULL;
            if(P==NULL)
            {
                P=temp;
                last=temp;
            }
            else
            {
                last->next=temp;
            last=temp;

            }
          
            
        }
          return P;
    }
};