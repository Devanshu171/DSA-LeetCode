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
    ListNode* reversel(ListNode* head){
        ListNode *cur=head,*prev=NULL;
        while(cur){
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        stack<int>st;
        head =reversel(head);
        for(ListNode *cur=head;cur;cur=cur->next){
            while(!st.empty() && st.top()<=cur->val){
                st.pop();
            }
            if(st.empty()) ans.push_back(0);
            else ans.push_back(st.top());
            st.push(cur->val);
        }
       head= reversel(head);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};