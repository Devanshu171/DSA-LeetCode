/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>st;
        TreeNode* node=root;
        
        while(node || !st.empty()){
            if(node){
                st.push(node);
            node=node->left;
            }
            else{
                TreeNode *temp=st.top()->right;
                if(!temp){
                    temp=st.top();
                    ans.push_back(temp->val);
                    st.pop();
                    while(!st.empty() && st.top()->right==temp){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                   
                }
                 else{
                        node=temp;
                    }
            }
        }
        return ans;
    }
};