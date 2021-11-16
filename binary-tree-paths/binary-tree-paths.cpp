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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if(!root) return res;
        stack<TreeNode*>st;
        stack<string>path;
        st.push(root);
        path.push(to_string(root->val));
        
        while(!st.empty()){
            TreeNode *cur=st.top();
            st.pop();
            string temp=path.top();
            path.pop();
            
            if(!cur->left && !cur->right)
                res.push_back(temp);
            
            if(cur->left){
                st.push(cur->left);
                path.push(temp+"->"+to_string(cur->left->val));
            }
            if(cur->right){
                st.push(cur->right);
                path.push(temp+"->"+to_string(cur->right->val));
            }
        }
        return res;
    }
};