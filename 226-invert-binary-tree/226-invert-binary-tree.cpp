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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*>st;
        if(!root)
            return root;
        st.push(root);
        while(!st.empty()){
            TreeNode *temp=st.top();
            st.pop();
            if(temp->left)  st.push(temp->left);
            if(temp->right) st.push(temp->right);
            TreeNode *tempright=temp->right;
            temp->right=temp->left;
            temp->left=tempright;
        }
        return root;
    }
};