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
    
    void flatten(TreeNode* root) {
        TreeNode* node=root,*Lnode=root,*last=NULL;
        
        stack<TreeNode*>st;
        st.push(node);
        
        while(!st.empty()){
            if(node){
                st.push(node->right);
                if(last==NULL){
                    last=node;
                }else{
                    last->right=node;
                    last=node;
                }
                TreeNode *temp=node->left;
                
                node->left=NULL;
                node=temp;
                
            }else{
                node=st.top();
                st.pop();
            }
        }
        
        
    }
};